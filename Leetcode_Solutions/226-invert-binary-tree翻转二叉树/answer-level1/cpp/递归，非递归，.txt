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
    TreeNode* invertTree(TreeNode* root) 
    {
        if(root==NULL)  return NULL;
        q.push(root);
        while(!q.empty())
        {
            int n=q.size();
            while(n--)
            {
                TreeNode *p=q.front();
                q.pop();
                if(p)
                {
                    swap(p->left,p->right);
                    q.push(p->left);
                    q.push(p->right);
                }
               
            }

        }
        return  root;


    //     if(root==NULL)  return NULL;
    //    TreeNode  *left=invertTree(root->left);
    //    TreeNode *right=invertTree(root->right);
    //    root->right=left;
    //    root->left=right;
    //    return root;
    }
    private:queue<TreeNode*> q;
};
```