解法：
1、从根节点开始计算左子树长度和右子树长度
    若子节点为空，则长度为0；
    若子节点不为空，则长度为1 + 子节点的子树长度
2、节点最长路径取左右子树中最长路径即可
3、每个节点的最长路径记录到全局变量中

复杂度分析：每个节点遍历一遍，时间复杂度O(N)

```
int g_ans = 0;
int deep(struct TreeNode* root) {
    int leftLength = 0;
    int rightLength = 0;
    int ret = 0;

    if (root != NULL) {
        leftLength = root->left ? deep(root->left) + 1 : 0;
        rightLength += root->right? deep(root->right) + 1 : 0;
        g_ans = (g_ans > leftLength + rightLength) ? g_ans : leftLength + rightLength;
        ret = (leftLength > rightLength) ? leftLength : rightLength;
        //printf("root->val = %d, leftLength = %d, rightLength = %d\n", root->val, leftLength, rightLength);
        return ret;
    }
    return 0;
}
int diameterOfBinaryTree(struct TreeNode* root){
    g_ans = 0;
    (void)deep(root);
    return g_ans;
}
```
