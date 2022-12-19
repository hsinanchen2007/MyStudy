__对二叉搜索树用中序遍历，遍历的节点顺序就是数字从小到大的顺序。__



![timg (1).jpg](https://pic.leetcode-cn.com/bbe8c07f25227d96367b39df48d4d6aa54848512517598643297a73a521b45a0-timg%20\(1\).jpg)
```
int min;
struct TreeNode* pre;
int minDiffInBST(struct TreeNode* root){
    min = 0x3f3f3f3f;
    pre = NULL;
    dfs(root);
    return min;
}

int dfs(struct TreeNode* root){
    if (root == NULL) return 0;
    dfs(root->left);
    if (pre != NULL) {
        if (min > (root->val - pre->val)) {
            min = root->val - pre->val;
        }
    }
    pre = root;
    dfs(root->right);
    return 0;
}
```
