![截图.PNG](https://pic.leetcode-cn.com/36d9a687faec94cf7fdcddc080322eb0160adb1117276041969a1ca17de22173-%E6%88%AA%E5%9B%BE.PNG)

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

int *rightSideView(struct TreeNode* root, int* returnSize){
    int *nums;
    struct numsList list[1000] = {0};
    int row, i, j;

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
    }
    *returnSize = row + 1;
    nums = (int *)malloc(sizeof(int) * (row + 1));
    if (nums == NULL) {
        return NULL;
    }
    for (i = 0; i < row + 1; i++) {
        for (j = 0; j <= g_len; j++) {
            if (i == list[j].layer) {
                nums[i] = list[j].num;
            }
        }
    }

    return nums;
}
```
