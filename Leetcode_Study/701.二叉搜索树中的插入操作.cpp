/*
 * @lc app=leetcode.cn id=701 lang=cpp
 *
 * [701] 二叉搜索树中的插入操作
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution100 {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode *curr = root, *parent = nullptr;
        while (curr) {
            parent = curr;
            if (val <= curr->val) {
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }
        if (!parent) {
            root = new TreeNode(val);
        } else if (val <= parent->val) {
            parent->left = new TreeNode(val);
        } else {
            parent->right = new TreeNode(val);
        }
        return root;
    }
};


class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) {
            root = new TreeNode(val);
        } else {
            if (val <= root->val) {
                root->left = insertIntoBST(root->left, val);
            } else {
                root->right = insertIntoBST(root->right, val);
            }
        }
        return root;
    }
};

// @lc code=end

