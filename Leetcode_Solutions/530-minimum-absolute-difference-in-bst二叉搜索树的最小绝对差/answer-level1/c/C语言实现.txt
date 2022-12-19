C语言实现
```C []
void getMinDiff(struct TreeNode* root, int* prev, int *min_diff){
    if (NULL == root) return;
    getMinDiff(root->left, prev, min_diff);
    if (root->val >= *prev && root->val - *prev < *min_diff) {
        *min_diff = root->val - *prev;
    }
    if (*min_diff == 0) return;
    *prev = root->val;
    getMinDiff(root->right, prev, min_diff);
}

int getMinimumDifference(struct TreeNode* root){
    int min_diff = 0x7fffffff, prev = 0x7fffffff;
    getMinDiff(root, &prev, &min_diff);
    return min_diff;
}
```
