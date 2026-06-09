### 解题思路
1.节点满足二叉搜索树的关键字的大小比较条件

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

bool nodefun(struct TreeNode* node, long low, long high) {
    if (node == NULL) return true;//递归结束条件1：到树叶子节点，返回true
    int val = node->val;
    if (val <= low || val >= high) return false;//递归结束条件2：节点不满足二叉搜索条件
    return nodefun(node->left, low, val) && nodefun(node->right, val, high);//进行递归条件：继续向下判断
}
bool isValidBST(struct TreeNode* root){
    return nodefun(root, LONG_MIN, LONG_MAX); //引入上下界保证左子树小于右子树，开始设置为无穷大小
}
```