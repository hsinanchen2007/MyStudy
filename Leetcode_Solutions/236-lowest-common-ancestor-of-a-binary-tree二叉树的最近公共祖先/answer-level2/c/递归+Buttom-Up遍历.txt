# 解法1：递归+Buttom-Up遍历
## 算法描述
维护两个bool变量，表示当前节点以及左右子树，是否包含p和q：
* 先在左子树尝试搜索p,q，若都找到，则为答案。
* 再在左子树尝试搜索p,q，若都找到，则为答案。
* 若当前节点为p，q中任一个，则先检查是否p,q都已找到，若找到，则当前节点为答案。

## 复杂度分析
时间复杂度：O（n）
空间复杂度：O（n）

## 提交结果
通过

## 参考代码
```
struct TreeNode* traverse(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q, bool *pfound, bool *qfound) {
    if (!root) {
        return NULL;
    }
    
    bool pf = false;
    bool qf = false;
    struct TreeNode* n = traverse(root->left, p, q, &pf, &qf);
    if (n) {
        return n;
    }
    *pfound = *pfound || pf;
    *qfound = *qfound || qf;
    
    pf = false;
    qf = false;
    n = traverse(root->right, p, q, &pf, &qf);
    if (n) {
        return n;
    }
    *pfound = *pfound || pf;
    *qfound = *qfound || qf;
    
    if (root == p) {
        *pfound = true;
    }
    
    if (root == q) {
        *qfound = true;
    }
    
    if (*pfound && *qfound) {
        return root;
    }
    
    return NULL;
}

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    bool pfound = false;
    bool qfound = false;
    return traverse(root, p, q, &pfound, &qfound);
}
```