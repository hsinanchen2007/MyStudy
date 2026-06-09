### 解题思路

二叉树的问题就是递归的问题。

对于以root为根节点的二叉树，和为sum 的路径包括两部分：
1. 包含节点root, 和为sum 的路径(对应题目中的`pathSumInclude`函数)
2. 不包含节点root, 和为 sum 的路径(对应题目中的`pathSumNoInclude`函数)
理解了这层，通过递归求解即可。
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

// 包换 root, 合为 sum 的路径数
int pathSumInclude(struct TreeNode* root, int sum) {
    if (root == NULL) {
        return 0;
    }
    int newSum = sum - root->val;
    int add = newSum == 0 ? 1 : 0;
    return pathSumInclude(root->left, newSum) + pathSumInclude(root->right, newSum) + add;
}

int pathSumNoInclude(struct TreeNode* root, int sum) {
    if (root == NULL) {
        return 0;
    }
    return pathSumInclude(root->left, sum) + pathSumInclude(root->right, sum) + pathSumNoInclude(root->left, sum) + pathSumNoInclude(root->right, sum);
}


int pathSum(struct TreeNode* root, int sum){
    return pathSumInclude(root, sum) + pathSumNoInclude(root, sum);
}
```