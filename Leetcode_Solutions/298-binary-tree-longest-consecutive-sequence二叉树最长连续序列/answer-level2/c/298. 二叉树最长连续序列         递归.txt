### 解题思路

给你一棵指定的二叉树，请你计算它最长连续序列路径的长度。

该路径，可以是从某个初始结点到树中任意结点，通过「父 - 子」关系连接而产生的任意路径。

这个最长连续的路径，必须从父结点到子结点，反过来是不可以的。

示例 1：

输入:

   1
    \
     3
    / \
   2   4
        \
         5

输出: 3

解析: 当中，最长连续序列是 3-4-5，所以返回结果为 3


递归可改下，  将parent node传参进来

### 代码

```c
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#define MAX(a,b) ((a) > (b) ? (a) : (b))
int max_len;
int helper(struct TreeNode* root, int len){
    max_len = MAX(len, max_len);

    if(root->left == NULL && root->right ==NULL)
        return max_len;

    if(root->left){
        if(root->val + 1 == root->left->val)
            helper(root->left, len +1);
        else
            //max_len = MAX(len, max_len);
            helper(root->left, 1);
    }
    if(root->right){
        if(root->val + 1 == root->right->val)
            helper(root->right, len + 1);
        else
            helper(root->right, 1);
    }
    //max_len = MAX(l,r);
    return max_len;
}


int longestConsecutive(struct TreeNode* root){
    max_len = 0;
    if(root == NULL)
        return max_len;
    else 
        return helper(root,1);
}
```