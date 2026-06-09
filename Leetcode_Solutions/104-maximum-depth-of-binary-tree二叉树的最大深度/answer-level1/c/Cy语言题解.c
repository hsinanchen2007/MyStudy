### 解题思路
1、算是全局变量的depth，记录最大的深度
2、递归统计左右子树的深度，每次获取最大值。

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

void nextDepth(struct TreeNode *root, int *depth)
{
    int depthLeft = *depth;
    int depthRight = *depth;   
    if (root == NULL) {
        return *depth;
    }

    depthLeft++;
    depthRight++;

    nextDepth(root->left, &depthLeft);
    nextDepth(root->right, &depthRight);
    *depth = (depthLeft > depthRight ? depthLeft : depthRight);
}

int maxDepth(struct TreeNode* root){
    int depth = 0;
    nextDepth(root, &depth);

    return depth;
}
```