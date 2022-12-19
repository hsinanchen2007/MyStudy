### 解题思路
递归实现二叉树的先序遍历

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
    vector<int> preorderTraversal(TreeNode* root) {
        //递归实现二叉树的前序遍历
        vector<int> v;
        preorder(root,v);
        return v;
    }
    void preorder(TreeNode* root,vector<int> &v){
        if(root!=NULL){
            v.push_back(root->val);
            preorder(root->left,v);
            preorder(root->right,v);
        }
    }
};
```