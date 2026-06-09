### 解题思路
此处撰写解题思路
（1）深度优先搜索，并按照顺序保存每个叶子结点及其长度；
（2）一次对比两个数组是否相同

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
#define ARRLEN 100

void myLeafSimilar(struct TreeNode *root, int *arr, int *len)
{
    if (root == NULL) {
        return;
    }

    if (root ->left == NULL && root->right == NULL) {
        arr[*len] = root->val;
        (*len)++;
    }
    myLeafSimilar(root->left, arr, len);
    myLeafSimilar(root->right, arr, len);
}

bool leafSimilar(struct TreeNode* root1, struct TreeNode* root2)
{
    int *arr1 = NULL;
    int *arr2 = NULL;
    int len1 = 0;
    int len2 = 0;
    int i;

    arr1 = (int *)malloc(sizeof(int) * ARRLEN);
    arr2 = (int *)malloc(sizeof(int) * ARRLEN);
    memset(arr1, 0, sizeof(int) * ARRLEN);
    memset(arr2, 0, sizeof(int) * ARRLEN);

    myLeafSimilar(root1, arr1, &len1);
    myLeafSimilar(root2, arr2, &len2);

    if (len1 != len2) {
        free(arr1);
        free(arr2);
        return false;
    }

    for (i = 0; i < len1; i++) {
        if (arr1[i] != arr2[i]) {
            free(arr1);
            free(arr2);
            return false;
        }
    }

    free(arr1);
    free(arr2);
    return true;
}

```