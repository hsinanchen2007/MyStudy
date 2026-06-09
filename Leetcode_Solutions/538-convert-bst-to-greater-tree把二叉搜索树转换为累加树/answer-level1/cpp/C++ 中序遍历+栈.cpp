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
    void inOrder(TreeNode* root,stack<TreeNode*>& s){
        if(!root)
            return;
        inOrder(root->left,s);
        s.push(root);
        inOrder(root->right,s);
    }
    TreeNode* convertBST(TreeNode* root) {
        stack<TreeNode*> s;
        inOrder(root,s);
        TreeNode* temp = new TreeNode(0);
        while(!s.empty()){
            s.top()->val += temp->val;
            temp = s.top();
            s.pop();
        };
        return root;
    }
};
```