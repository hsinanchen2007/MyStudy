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
    int find,size=0;

    int kthSmallest(TreeNode* root, int k) 
    {
        inorder(root,k);
        return find;
    }

    void inorder(TreeNode* root,int k)
    {
        if(root)
        {
            if(root->left) inorder(root->left,k);

            if(++size==k) 
            {
                find=root->val;
                return;
            }

            if(root->right) inorder(root->right,k);
        }
    }
};
```