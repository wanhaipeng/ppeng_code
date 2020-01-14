/**
 *  @file    PathSum.hpp
 *  @brief   LeetCode problems 113: find all path that path sum is equals target sum.
 *  @author  ppeng
 *  @date    2020-01-14
 */
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "extend.hpp"

using std::vector;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 private:
  void pathSum_inner(TreeNode* node, vector<vector<int>>& all_path, int sum, vector<int> inner_vec) {
    // process boundary condition
    if (node == NULL) { return; }
    int val = node->val;
    inner_vec.emplace_back(val);
    int next_sum = sum - node->val;
    // insert pathSum
    if (next_sum == 0 && node->left == NULL && node->right == NULL) {
      all_path.emplace_back(inner_vec);
      return;
    }
    // search left subtree
    pathSum_inner(node->left, all_path, next_sum, inner_vec);
    // search right subtree
    pathSum_inner(node->right, all_path, next_sum, inner_vec);
  }
 public:
  vector<vector<int>> pathSum(TreeNode* root, int sum) {
    // init vector<vector>
    vector<vector<int>> all_path;
    // process boundary condition
    if (root == NULL) { return all_path; }
    int val = root->val, next_sum = sum - root->val;
    vector<int> root_vec;
    root_vec.emplace_back(val);
    if (root->left == NULL && root->right == NULL && next_sum == 0) {
      all_path.emplace_back(root_vec);
    }
    // search left subtree
    pathSum_inner(root->left, all_path, next_sum, root_vec);
    // search right subtree
    pathSum_inner(root->right, all_path, next_sum, root_vec);
    return all_path;
  }
};