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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> s;
        TreeNode* lastvisit=root;
        if(root==NULL)return result;
        while(!s.empty()||root){
            if(root){
                s.push(root);
                root=root->left;
            }else{
                    root=s.top();
                if(root->right==NULL||lastvisit==root->right){
                    result.push_back(root->val);
                    s.pop();
                    lastvisit=root;
                    root=NULL;
                }else{
                    root=root->right;
                }
            }
        }
        return result;
    }
};
```