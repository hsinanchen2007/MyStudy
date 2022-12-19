### 解题思路
找到叶子结点返回0；
左边的结点返回左边路径的个数；
右边的结点返回右边路径的个数；
左边+右边如果比g_Max大，则保留；否则丢弃；
最终返回g_Max即可。
![123.PNG](https://pic.leetcode-cn.com/a5bbdfd2df41b74ad42b5271bf22897ab92c5e98ebfc47a47839caa314fdfdaa-123.PNG)


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

int g_Max;
int NodePath(struct TreeNode *root) {
    if (root == NULL) {
        return 0;
    }
    int leftMax, rightMax;
    leftMax = rightMax = 0;
    leftMax += NodePath(root->left);
    rightMax += NodePath(root->right);
    if (leftMax + rightMax >= g_Max) {
        g_Max = leftMax + rightMax;
    }
    return leftMax >= rightMax ? (leftMax + 1) : (rightMax + 1);
}

int diameterOfBinaryTree(struct TreeNode* root){
    g_Max = 0;
    int ret = NodePath(root);
    return g_Max;
}

```