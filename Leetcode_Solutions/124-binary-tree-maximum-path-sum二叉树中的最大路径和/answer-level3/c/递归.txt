### 解题思路
递归

### 代码

```c

#define MAX(a, b) (((a) > (b))? (a) : (b))
int maxPathSumDFS(struct TreeNode* root, int *max){
    int lVal, rVal, ret, lTree, rTree;
    if (root == NULL) {
        return 0;
    }
    lVal = maxPathSumDFS(root->left, max);
    rVal = maxPathSumDFS(root->right, max);
    lTree = root->val + MAX(0, lVal) + MAX(0, rVal);
    rTree = root->val + MAX(0, MAX(lVal, rVal));
    *max = MAX(*max, MAX(lTree, rTree));
    return rTree;
}
int maxPathSum(struct TreeNode* root){
    int max = INT_MIN;
    maxPathSumDFS(root, &max);
    return max;
}
```