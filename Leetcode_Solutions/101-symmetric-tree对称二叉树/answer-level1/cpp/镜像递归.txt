### 解题思路
由于每一对节点判断的操作差不多，所以可以采用递归。
![捕获.PNG](https://pic.leetcode-cn.com/57a9ac4d50969fcfa07119b3a8f1765ffbf775b112a7858769d0f38c49d47743-%E6%8D%95%E8%8E%B7.PNG)


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
    bool isSame(TreeNode* left, TreeNode* right)
    {
        if(left == NULL && right == NULL)return true;
        else if(left != NULL && right != NULL && left->val == right->val)
        {
            return isSame(left->left, right->right) & isSame(left->right, right->left);
        }
        else return false;
    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)return true;
        else return isSame(root->left, root->right);
    }
};
```