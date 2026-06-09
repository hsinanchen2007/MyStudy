

执行用时 :6 ms, 在所有 C 提交中击败了100.00%的用户
内存消耗 :10.2 MB, 在所有 C 提交中击败了100.00%的用户


```
bool isBalanced(struct TreeNode* root){
    return (isba_dfs(root) < 0 ? false : true);
}
int isba_dfs(struct TreeNode* root)
{
    if (root == NULL) return 0;
    int left_layer = isba_dfs(root->left);
    if (left_layer < 0) return -1;
    
    int right_layer = isba_dfs(root->right);
    if (right_layer < 0) return -1;
    
    int tmp = left_layer - right_layer;

    if ((tmp >= -1) && (tmp <= 1)) {
        return (1 + (left_layer > right_layer ? left_layer : right_layer));
    }
    return -1;   
}
```
