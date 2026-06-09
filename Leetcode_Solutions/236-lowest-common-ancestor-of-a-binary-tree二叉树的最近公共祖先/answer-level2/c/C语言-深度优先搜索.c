```
C语言
```
```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 struct TreeNode* pRes = NULL;
 int g_flag = 0;
 int dfs(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    int ret = 0;
    if(root == NULL) {
        return 0;
    }
    if (root->val == p->val) {
        ret += 1;
    }
    if (root->val == q->val) {
        ret += 1;
    }
    ret += dfs(root->left,p,q);
    ret += dfs(root->right,p,q);

    //左子树加上右子树加上根，第一返回2，证明找到了，就是结果。
    if (ret == 2 && g_flag == 0) {
       g_flag = 1;
       pRes = root;
    }
    return ret;
 }
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    pRes = NULL;
    g_flag = 0;
    dfs(root,p,q);
    return pRes;  
}
```

```

```
