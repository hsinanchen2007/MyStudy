```
int cmp(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}
void* getElement(struct TreeNode* root, int* ret, int* returnSize)
{
    if (root == NULL) {
        return;
    }
    ret[(*returnSize)++] = root->val;
    getElement(root->left, ret, returnSize);
    getElement(root->right, ret, returnSize);
}
int* getAllElements(struct TreeNode* root1, struct TreeNode* root2, int* returnSize)
{
    *returnSize = 0;
    if (root1 == NULL && root2 == NULL) {
        return NULL;
    }
    int* ret = (int*)malloc(sizeof(int) * 10000);
    getElement(root1, ret, returnSize);
    getElement(root2, ret, returnSize);
    qsort(ret, *returnSize, sizeof(int), cmp);
    return ret;
}
```
