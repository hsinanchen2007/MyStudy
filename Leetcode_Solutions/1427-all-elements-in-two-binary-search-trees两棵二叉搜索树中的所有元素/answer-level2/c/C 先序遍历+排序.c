```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode stack[5000] = {0};
int top = 0;
int cmp(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}
void push(struct TreeNode *root)
{
    stack[top].val = root->val;
    stack[top].left = root->left;
    stack[top].right = root->right;
    top++;
}
void pop(struct TreeNode *root)
{
    top--;
    root->val = stack[top].val;
    root->left = stack[top].left;
    root->right = stack[top].right;
}
int* getNumArray(struct TreeNode* root, int *returnSize)
{
    int *array, cnt = 0;
    struct TreeNode* curr = root;
    struct TreeNode next;
    top = 0;
    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }
    array = calloc(5000, sizeof(int));
    curr = root;
    while ((curr != NULL) || (top > 0)) {
        while (curr != NULL) {
            array[cnt++] = curr->val;
            push(curr);
            curr = curr->left;
        }
        pop(&next);
        if (next.right != NULL) {
            curr = next.right;
        }
    }
    *returnSize = cnt;
    return array;
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getAllElements(struct TreeNode* root1, struct TreeNode* root2, int* returnSize){
    int *a, *b, cnt1, cnt2, *result;
    a = getNumArray(root1, &cnt1);
    b = getNumArray(root2, &cnt2);
    result = calloc(cnt1+cnt2, sizeof(int));
    for (int i = 0; i < cnt1; i++) {
        result[i] = a[i];
    }
    for (int j = 0; j < cnt2; j++) {
        result[cnt1 + j] = b[j];
    }
    qsort(result, cnt1 + cnt2, sizeof(int), cmp);
    *returnSize = cnt1 + cnt2;
    return result;
}
```
