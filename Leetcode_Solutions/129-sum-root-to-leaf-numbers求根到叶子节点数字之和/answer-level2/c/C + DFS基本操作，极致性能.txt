```c
int helper(struct TreeNode *root, int sum, int *total)
{
    sum = sum * 10 + root->val;
    if ((root->left == NULL) && (root->right == NULL)) {
        *total += sum;
        return 0;
    }
    root->left && helper(root->left, sum, total);
    root->right && helper(root->right, sum, total);
    return 0;
}

int sumNumbers(struct TreeNode* root){
    if (root == NULL) return 0;
    int total = 0;
    (void)helper(root, 0, &total);
    return total;
}
```
![image.png](https://pic.leetcode-cn.com/986db055cb1c16eb9c52c528514ae401ecdb21dc4b8374b3f1f3e42688cd4e38-image.png)



