### 解题思路
递归
与辅助栈迭代

### 代码

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//递归前序遍历
class Solution {
public:
    void helper(TreeNode* root , vector<int>& result) {
        if(root == NULL)return;
        result.push_back(root->val);
        helper(root -> left ,  result);
        helper(root -> right ,  result);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        helper(root, result);
        return result;
    }
};
/* 辅助栈迭代前序遍历
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> S;
        S.push(root);
        vector<int> result;
        if(root == NULL)return result;
        while(!S.empty()){
            TreeNode* cur = S.top();
            S.pop();
            result.push_back(cur->val);
            if(cur->right != NULL){
                S.push(cur->right);
            }
            if(cur->left != NULL){
                S.push(cur->left);
            }
        }
        return result;
    }
};*/

```