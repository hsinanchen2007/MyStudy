### 解题思路
官方题解的C实现...

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

int getMax(int a, int b)
{
    if (a > b) {
        return a;
    }
    return b;
}

int getArrowLength(struct TreeNode* node, int* diagmeter) 
{
    if (node == NULL) {
        return 0;
    }

    int left = getArrowLength(node->left, diagmeter);
    int right = getArrowLength(node->right, diagmeter);

    int ArrowLeft = 0;
    int ArrowRight = 0;
    if ((node->left != NULL) && (node->val == node->left->val)) {
        ArrowLeft = 1 + left;
    }
    if ((node->right != NULL) && (node->val == node->right->val)) {
        ArrowRight = 1 + right;
    }

    *diagmeter = getMax(*diagmeter, ArrowLeft + ArrowRight);
    return getMax(ArrowLeft, ArrowRight);
}

int longestUnivaluePath(struct TreeNode* root) {
    int diagmeter = 0;
    getArrowLength(root, &diagmeter);
    return diagmeter;
}
```