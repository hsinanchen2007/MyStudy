/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
二叉树转数组，然后排序，最后输出
#define MAXLEN 1024
void GetSecondsmall(struct TreeNode* root, int ret[], int *num)
{
    if (ret == NULL) {
        return;
    }
    ret[*num] = root->val;
    (*num)++;
    if (root->left != NULL) {
        GetSecondsmall(root->left, ret, num);
    }
    if (root->right != NULL) {
        GetSecondsmall(root->right, ret, num);
    }
    return;
}
int Cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}
int findSecondMinimumValue(struct TreeNode* root){
    int *ret = (int *)malloc(sizeof(int) * MAXLEN);
    if (ret == NULL) {
        return -1;
    }
    int num = 0;
    memset(ret, 0, sizeof(int) * MAXLEN);
    GetSecondsmall(root, ret, &num);
    qsort(ret, num, sizeof(int), Cmp);
    int secondsmall = ret[0];
    int i = 0;
    for (i = 1; i < num; i++) {
        if (ret[i] > secondsmall) {
            return ret[i];
        }
    }
    free(ret);
    return -1;
}