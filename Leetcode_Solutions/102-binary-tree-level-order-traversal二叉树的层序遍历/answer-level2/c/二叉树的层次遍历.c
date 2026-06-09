```
struct numsList {
    int num;
    int layer;
};

int g_len;
void PreOrder(struct TreeNode *root, struct numsList *list, int row)
{
    list[g_len].num = root->val;
    list[g_len].layer = row;
    if (root->left != NULL) {
        g_len++;
        (void)PreOrder(root->left, list, row + 1);
    }
    if (root->right != NULL) {
        g_len++;
        (void)PreOrder(root->right, list, row + 1);
    }
}

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    int **nums;
    struct numsList list[10000] = {0};
    int row, i, j, k;
    int cols[10000] = {0};

    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }

    row = 0;
    g_len = 0;
    PreOrder(root, list, row);
    for (i = 0; i <= g_len; i++) {
        if (row < list[i].layer) {
            row = list[i].layer;
        }
        cols[list[i].layer]++;
    }
    *returnSize = row + 1;
    *returnColumnSizes = malloc(sizeof(int) * (*returnSize));
    if (*returnSize == NULL) {
        return NULL;
    }
    nums = (int **)malloc(sizeof(int *) * (row + 1));
    if (nums == NULL) {
        return NULL;
    }
    for (i = 0; i < row + 1; i++) {
        (*returnColumnSizes)[i] = cols[i];
        nums[i] = (int *)malloc(sizeof(int) * cols[i]);
        if (nums[i] == NULL) {
            return NULL;
        }
        j = 0;
        for (k = 0; k <= g_len; k++) {
            if (i == list[k].layer) {
                nums[i][j] = list[k].num;
                j++;
            }
        }
    }

    return nums;
}
```
