### 解题思路
此处撰写解题思路

### 代码

```c

typedef struct TreeNode TreeNode;
#define MAX_LEN 1000

void preOrder(TreeNode *root, int **ans, int *size, int col, int *colSize, int sum, int target)
{
    if ((root == NULL) ) {
        return;
    }

    if (((sum + root->val) == target) && (root->left == NULL) && (root->right == NULL)) {
        ans[*size][col++] = root->val;
        colSize[*size] = col;
        (*size)++;
        memcpy(ans[*size], ans[(*size) - 1], (col - 1) * sizeof(int));
        return;
    }

    ans[*size][col++] = root->val;
    sum = sum + root->val;
    printf("%d\n", root->val);
    preOrder(root->left, ans, size, col, colSize, sum, target);
    preOrder(root->right, ans, size, col, colSize, sum, target);

    return;
}

int **pathSum(struct TreeNode *root, int sum, int *returnSize, int **returnColumnSizes)
{
    int **ans = (int **)malloc(sizeof(int *) * MAX_LEN);
    int *colSize = (int *)malloc(sizeof(int) * MAX_LEN);
    int sum1 = 0;
    int index = 0;

    for (int i = 0; i < MAX_LEN; i++) {
        ans[i] = (int *)malloc(sizeof(int) * MAX_LEN);
        memset(ans[i], 0x0, sizeof(int) * MAX_LEN);
    }
    
    // 先序遍历
    preOrder(root, ans, &index, 0, colSize, sum1, sum);
    *returnSize = index;
    *returnColumnSizes = colSize;

    return ans;
} 
```