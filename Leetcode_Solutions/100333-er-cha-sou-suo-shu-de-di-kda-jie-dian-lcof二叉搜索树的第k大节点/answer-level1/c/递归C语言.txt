注意使用全局变量时，记得在当前调用函数中进行初始化
```
int ans;
int count;

void preOrder(struct TreeNode *root, int k)
{
    if (root == NULL) {
        return;
    }

    preOrder(root->right, k);
    count++;
    if (count == k) {
        ans = root->val;
    }
    preOrder(root->left, k);
    return;
}

int kthLargest(struct TreeNode* root, int k)
{
    ans = 0;
    count = 0;

    preOrder(root, k);

    return ans;
}
```
