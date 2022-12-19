### 解题思路
１．参考精选题解
２．每往下一层，从下一层开始数，都是新的路径

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
int dfs(struct TreeNode* root, int sum, int* arr, int arrlen){
    if(root == NULL)
        return 0;

    int i = arrlen, temp=0;
    int n = 0, l, r;

    arr[arrlen] = root->val;
    while (i >= 0) {
        temp += arr[i--];
        if (temp == sum)
            n++;
    }
    
    l = dfs(root->left, sum, arr, arrlen + 1);
    r = dfs(root->right, sum, arr, arrlen + 1);
    return n + l + r;
}

int pathSum(struct TreeNode* root, int sum){
    int * arr = malloc(1000 * sizeof(int));
    return dfs(root, sum, arr, 0);
}
```