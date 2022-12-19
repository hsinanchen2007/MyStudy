![image.png](https://pic.leetcode-cn.com/21e1d22756798839c6f56b452b344c92308462a8d22295361d3e103f84a49d82-image.png)


```
bool hasPathSum(struct TreeNode* root, int sum){
    if (root == NULL) {
        return false;
    }

    if (root->left == NULL && root->right == NULL) {
        return (sum == root->val);
    }

    int remainSum = sum - root->val;

    return hasPathSum(root->left, remainSum) || hasPathSum(root->right, remainSum);
}
```

