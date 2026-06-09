
```
//整数转字符串
int intToString(int val, char** ans, int* returnSize, int currIndex)
{
    int temp[100];
    int index = 0;
    if (val < 0) {
        ans[*returnSize][currIndex++] = '-';
        val = -val;
    }
    while (val / 10 != 0) {
        temp[index++] = val % 10;
        val /= 10;
    }
    temp[index] = val;
    for (int i = index; i >= 0; --i) {
        ans[*returnSize][currIndex++] = (char)(temp[i] + '0');
    } 
    return currIndex;
}
//深度搜索
void findPath(struct TreeNode* root, char** ans, int* returnSize, int currIndex)
{
    if (root == NULL) {
        return;
    }
    currIndex = intToString(root->val, ans, returnSize, currIndex);

    if (root->left == NULL && root->right == NULL) {
        ans[*returnSize][currIndex] = '\0';
        return;
    }
    ans[*returnSize][currIndex++] = '-';
    ans[*returnSize][currIndex++] = '>';
    findPath(root->left, ans, returnSize, currIndex);

    if (root->right != NULL) {
        if (root->left != NULL) {
            //右侧分支也存在意味着路径增加了一条
            (*returnSize)++;
            for (int i = 0; i <= currIndex; ++i) {
                ans[*returnSize][i] = ans[*returnSize - 1][i];
            }
        }
        findPath(root->right, ans, returnSize, currIndex);
    }
}
//入口函数
char** binaryTreePaths(struct TreeNode* root, int* returnSize)
{
    char** ans = (char**)malloc(100 * sizeof(char*));
    for (int i = 0; i < 100; ++i) {
        ans[i] = (char*)malloc(100 * sizeof(char));
    }
    *returnSize = 0; //总行数
    int currIndex = 0; //当前深度索引
    if (root == NULL) {
        return ans;
    }
    findPath(root, ans, returnSize, currIndex);
    (*returnSize)++;
    return ans;
}
```

