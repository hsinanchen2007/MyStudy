### 解题思路
 //只有与当前节点值相等，才能加权并返回。


给定一个二叉树，找到最长的路径，这个路径中的每个节点具有相同值。 这条路径可以经过也可以不经过根节点。

注意：两个节点之间的路径长度由它们之间的边数表示。

示例 1:

输入:

              5
             / \
            4   5
           / \   \
          1   1   5


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

#define MAX(a,b) ((a)>(b)?(a):(b))
int g_max;
int helper(struct TreeNode* root){
    if(root == NULL)
        return 0;

    //递归里搞两组left 和right，一组用来表示子树的返回值， 一组用来返会给父节点用
    int l=0, r=0, real_l = 0, real_r = 0;

    l = helper(root->left);
    r = helper(root->right);

    //只有与当前节点值相等，才能加权并返回。
    if (root->left && root->val == root->left->val)
            real_l = 1 + l;
    
    if (root->right && root->val == root->right->val)
            real_r = 1 + r;
    
    //每个节点，都与最大值比较下
    g_max = MAX(g_max, real_l + real_r);

    //返回值要给父一级用，当左右都与当前节点相等时，只能选一个较大值，不能相加。
    return MAX(real_l,real_r);
}

int longestUnivaluePath(struct TreeNode* root){
    g_max = 0;

    helper(root);
    
    return g_max;
}
```