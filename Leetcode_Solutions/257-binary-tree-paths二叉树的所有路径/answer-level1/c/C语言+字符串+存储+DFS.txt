### 解题思路
此处撰写解题思路

字符串的运用：
（1）sprintf将整数转为字符串；
（2）strlen求字符串的长度；
（3）strcat将dest复制到src的后边

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


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAXSIZE 1000

int g_col = 0;

void myBinaryTreePaths(struct TreeNode *root, char **arr, int *temp, int index)
{
    int i, j;
    char charTemp[100] = {'\0'};
    memset(charTemp, '\0', 100);

    if (root == NULL) {
        return;
    }

    temp[index++] = root->val;
    if (root->left == NULL && root->right == NULL) {
        arr[g_col] = (char *)malloc(sizeof(char) * MAXSIZE);
        memset(arr[g_col], '\0', sizeof(char) * MAXSIZE);

        for (i = 0, j = 0; i < index - 1; i++) {
            sprintf(charTemp, "%d", temp[i]);
            strcat(arr[g_col] + strlen(arr[g_col]), charTemp);
            strcat(arr[g_col] + strlen(arr[g_col]), "->");
            memset(charTemp, '\0', 100);
        }

        sprintf(charTemp, "%d", temp[i]);
        strcat(arr[g_col] + strlen(arr[g_col]), charTemp);
        g_col++;
    }
    
    myBinaryTreePaths(root->left, arr, temp, index);
    myBinaryTreePaths(root->right, arr, temp, index);
}

char ** binaryTreePaths(struct TreeNode* root, int* returnSize){
    char **arr = NULL;  //返回的数组
    int *temp;          //记录从根节点到叶子结点的路径值
    int index;          //代表列

    *returnSize = 0;
    if (root == NULL) {
        return NULL;
    }

    g_col = 0;

    arr = (char **)malloc(sizeof(char *) * MAXSIZE);
    temp = (int *)malloc(sizeof(int *) * MAXSIZE);

    myBinaryTreePaths(root, arr, temp, index);
    free(temp);
    *returnSize = g_col;
    return arr;
}

```