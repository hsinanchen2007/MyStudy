### 解题思路
此处撰写解题思路

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
int max(int a, int b){
    return a < b ? b : a;
}
int MaxRoot(struct TreeNode *root, int *sum){
    if(root == NULL) return 0;
    int left = MaxRoot(root->left, sum);
    int right = MaxRoot(root->right, sum);
    int new = left + right + 1;
    *sum = max(*sum, new);
    return max(left, right) + 1;
}
int diameterOfBinaryTree(struct TreeNode* root){
    if(root == NULL) return 0;
    int *sum = (int*)malloc(sizeof(int));
    *sum = 0;
    MaxRoot(root, sum);
    return *sum-1;
}


```