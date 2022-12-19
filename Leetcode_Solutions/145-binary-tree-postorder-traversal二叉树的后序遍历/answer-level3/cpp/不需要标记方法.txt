### 解题思路
如代码所示。
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
        vector<int> res;
        stack<TreeNode*> s;
        while(root || !s.empty())
        {
            while(root)
            {
                s.push(root);
                if(root->left)
                    root = root->left;
                else
                    root = root->right;
            }
            root = s.top();
            s.pop();
            res.push_back(root->val);
            if(!s.empty() && s.top()->left == root)
            {
                root = s.top()->right;
            }
            else
            {
                root = NULL;
            }
           
        }
        return res;
    }
};
```