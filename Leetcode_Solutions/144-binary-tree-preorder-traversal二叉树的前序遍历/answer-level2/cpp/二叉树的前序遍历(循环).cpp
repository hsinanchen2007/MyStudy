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
class Solution 
{
public:
    vector<int> preorderTraversal(TreeNode* root) 
    {
        vector<int>v;
        stack<TreeNode*>s;

       while(root || !s.empty())
       {
           if(root)
           {
               v.push_back(root->val);
               s.push(root);
               root=root->left;
           }
           else
           {
               root=s.top()->right;
               s.pop();
           }
       } 

       return v;
    }
};
```