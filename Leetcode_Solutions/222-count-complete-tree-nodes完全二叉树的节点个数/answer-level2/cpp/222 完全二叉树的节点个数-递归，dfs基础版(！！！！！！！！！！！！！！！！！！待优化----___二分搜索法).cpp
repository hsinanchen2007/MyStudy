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
private:
    int sum=0;
public:
    int countNodes(TreeNode* root) 
    {
        if(root==NULL)
            return 0;

        if(root->left!=NULL&&root->right==NULL)
            return countNodes(root->left)+1;

        if(root->right!=NULL)
            return countNodes(root->left)+countNodes(root->right)+1;
        return 1;

    }
};
```