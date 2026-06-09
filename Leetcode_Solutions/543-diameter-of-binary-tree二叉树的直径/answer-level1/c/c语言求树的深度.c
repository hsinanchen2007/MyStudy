### 解题思路
1.首先读题
2.将题目转化成模型：遍历每个节点，每个节点去求左边和右边的深度，并求和，输出最大和
3.最大和输出到全局变量g_max = 0
4.定义Dfs,为以root为根，最大的深度。
5.由于深度需要判断左边和右边，所以自然记录了中间变量并求值

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
int g_max = 0;

int Dfs(struct TreeNode* root) {
    if (root == NULL)
        return 0;
    int left = Dfs(root->left);
    int right = Dfs(root->right);

    if (left + right > g_max){
        g_max = left + right;
    }
    
    return (left+1) > (right+1) ? (left+1) : (right+1);
}

int diameterOfBinaryTree(struct TreeNode* root){
    g_max = 0;
    Dfs(root, 0);
    return g_max;
}
```