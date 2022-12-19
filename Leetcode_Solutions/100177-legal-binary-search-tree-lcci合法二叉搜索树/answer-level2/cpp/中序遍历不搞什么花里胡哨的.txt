### 解题思路
直接中序遍历一次即可

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
    long long  pre=LLONG_MIN;int flag=0;int count=0;
    void inorder(TreeNode* root)
    {
        if(root)
        {
            inorder(root->left);
            if(root->val>pre)
                pre=(long long)root->val;
            else
            flag=1;
            inorder(root->right);
        }
    }
    bool isValidBST(TreeNode* root) {
        inorder(root);
        if(flag==1)
            return 0;
        return 1;
    }
};
```