### 解题思路
C语言-递归

### 代码

```c

#define MAX(a, b) (((a) > (b))?(a):(b))
char ***retTDArray;
int **columSize;
int treeLevel;
int getTreeLevel(struct TreeNode* root) {
    int ret = 1, lLevel, rLevel;
    if (root == NULL) {
        return 0;
    }
    lLevel = getTreeLevel(root->left);
    rLevel = getTreeLevel(root->right);
    ret += MAX(lLevel, rLevel);
    return ret;
}
void makeTreeArray(struct TreeNode* root, int level, int left, int right){
    int rootPos, len;
    char tmp[100] = {0};

    if ((level >= treeLevel) || (left > right) || (root == NULL)) {
        return;
    }
    rootPos = (right + left)/2;
    sprintf(tmp, "%d", root->val);
    len = strlen(tmp);
    retTDArray[level][rootPos] = (char *)calloc(len + 1, sizeof(char));
    memcpy(retTDArray[level][rootPos], tmp, len*sizeof(char));
    makeTreeArray(root->left, level + 1, left, rootPos - 1);
    makeTreeArray(root->right, level + 1, rootPos + 1, right);
}

char *** printTree(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    int i, j, k, len;
    treeLevel = getTreeLevel(root);
    len = pow(2, treeLevel) - 1;
    printf("treeLevel:%d, size:%d\n",treeLevel, len);
    retTDArray = (char ***)calloc(treeLevel, sizeof(char **));
    *returnColumnSizes = (int *)calloc(treeLevel, sizeof(int));
    for (i = 0; i < treeLevel; i++) {
        (*returnColumnSizes)[i] = len;
        retTDArray[i] = (char **)calloc(len, sizeof(char *));
        for (j = 0; j < len; j++) {
            retTDArray[i][j] = (char *)calloc(1, sizeof(char ));
        }
    }
    makeTreeArray(root, 0, 0, len);
    *returnSize = treeLevel;
    return retTDArray;
}
```