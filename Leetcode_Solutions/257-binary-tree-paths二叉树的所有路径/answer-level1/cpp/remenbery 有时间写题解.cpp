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
    vector<string> binaryTreePaths(TreeNode* root)
    {
        vector<string> res;

        if(root==NULL)
         return res;

         if(root->left==NULL&&root->right==NULL)
         {
             res.push_back(to_string(root->val));
             return res;
         }

          vector<string> lef=binaryTreePaths(root->left);
         for(int i=0;i<lef.size();i++)
         {
             res.push_back(to_string(root->val)+"->"+(lef[i]));
         }

           vector<string> rig=binaryTreePaths(root->right);
         for(int i=0;i<rig.size();i++)
         {
             res.push_back(to_string(root->val)+"->"+(rig[i]));
         }
         return res;

    }
};
```