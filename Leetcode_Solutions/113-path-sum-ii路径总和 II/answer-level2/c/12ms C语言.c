```
#define MAX_PATH 1000
int IsLeaf(struct TreeNode *root) {
    return !(root->left || root->right);
}

void travelTree(struct TreeNode* root, int sum, int *curPath, int *curPathCount, int **allPath,int *allPathCount, int *count) {
    if (IsLeaf(root)) {
        if (root->val == sum) {
            int *path = (int*) malloc(sizeof(int) * (*curPathCount + 1));
            for (int i = 0; i < *curPathCount; ++i) {
                path[i] = curPath[i];
            }
            path[*curPathCount] = root->val;
            allPath[*count] = path;
            allPathCount[*count] = *curPathCount + 1;
            (*count)++;
        }
        return;
    }
    curPath[*curPathCount] = root->val;
    (*curPathCount)++;

    if (root->left) {
        travelTree(root->left, sum - root->val, curPath, curPathCount, allPath, allPathCount, count);
    }
    if (root->right) {
        travelTree(root->right, sum - root->val, curPath, curPathCount, allPath, allPathCount, count);
    }
    (*curPathCount)--;
}

int** pathSum(struct TreeNode* root, int sum, int* returnSize, int** returnColumnSizes){
    if (!root) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }
    int *allPath[MAX_PATH] = {NULL};
    int allPathCount[MAX_PATH] = {0};
    int currentPath[10000];
    int curPathCount = 0;
    int count = 0;

    travelTree(root, sum, currentPath, &curPathCount, allPath, allPathCount,  &count);

    *returnSize = count;

    int **returnPath = (int **)malloc(sizeof(int*) * count);
    *returnColumnSizes = (int *)malloc(sizeof(int) * count);

    for (int i = 0; i < count; i++) {
        returnPath[i] = allPath[i];
        (*returnColumnSizes)[i] = allPathCount[i];
    }
    return returnPath;
}
```
