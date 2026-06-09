### 解题思路
此处撰写解题思路

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
class Solution {
public:
    vector<int> result;
    stack<TreeNode*> Stack;
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode*tem=root;
        if(root==NULL) return result;
        while(true)
        {
            goalong(tem,Stack);
            if(Stack.empty()) break;
            tem=Stack.top();
            result.push_back(tem->val);
            Stack.pop();
            tem=tem->right;
        }
        return result;

    }
    void goalong(TreeNode *cur,stack<TreeNode*> s)
    {while(cur){Stack.push(cur);cur=cur->left;}}
};
        /*if(root==NULL) return result;
        if(root->left) inorderTraversal(root->left);
        result.push_back(root->val);
        if(root->right) inorderTraversal(root->right);    
        return result;  递归算法  */

```