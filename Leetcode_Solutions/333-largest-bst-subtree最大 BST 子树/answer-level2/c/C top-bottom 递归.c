![image.png](https://pic.leetcode-cn.com/dab7e0238b3c330382524b453654755d65e1af4599f57598763eac7901f50ed1-image.png)

### 解题思路
利用isValidBST验证是否是二叉搜索树的函数
递归法

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
// top-to-bottom
int max(int a, int b){
    return a > b ? a : b;
}
int treeSize(struct TreeNode* root){
    if(!root) return 0;     
    return treeSize(root->left) + treeSize(root->right) + 1;
}
bool nodefun(struct TreeNode* node, long low, long high) {
    if (node == NULL) return true;
    int val = node->val;
    if (val <= low || val >= high) return false;
    return nodefun(node->left, low, val) && nodefun(node->right, val, high);
}
bool isValidBST(struct TreeNode* root){
    return nodefun(root, LONG_MIN, LONG_MAX);
}
int largestBSTSubtree(struct TreeNode* root){
    if(!root) return 0;
    if(isValidBST(root)){
        return treeSize(root);//第一个得到的BST就是最大的
    }
    //否则，继续检查左/右子树，取个最大值
    return max(largestBSTSubtree(root->left), largestBSTSubtree(root->right));
}


```