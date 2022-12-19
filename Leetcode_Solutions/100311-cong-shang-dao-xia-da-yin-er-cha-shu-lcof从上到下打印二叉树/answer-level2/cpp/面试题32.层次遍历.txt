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
    vector<int> levelOrder(TreeNode* root) {
        vector<int> view;
        queue<TreeNode*> Q;
        Q.push(root);
        if(!root)
            return {};  
        while(!Q.empty())
        {
            TreeNode* node=Q.front();
            Q.pop();
            view.push_back(node->val);
            
            if(node->left)
            {
                 Q.push(node->left);
            }
            if(node->right)
            {
                Q.push(node->right);
            }
        } 
        return view;
    }
};
```