### 解题思路
    int left = maxDepth(root->left);
    int right = maxDepth(root->right);
这个地方改成这样，而不是MAX（maxDepth(root->left)， maxDepth(root->right)）时间就够了，这个地方没想明白

### 代码

```c
#define MAX(a, b) ((a) > (b) ? (a): (b))

int maxDepth(struct TreeNode* root)
{

    if (root == NULL) {
        return 0;
    }

    int left = maxDepth(root->left);
    int right = maxDepth(root->right);

    return 1 + MAX(left, right);
}
```