### 解题思路
1. 当做普通树来搜索
2. 只要找到一点，这一点到根路径都是true,   当p q两条路径相交时就是公共

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
struct TreeNode* gnode;
bool search(struct TreeNode* node, int p, int q){
    bool l = false, r = false, cur = false;

    if(node == NULL)
        return false;
    if (node->val == p || node->val == q)
        cur = true;
    l = search(node->left, p, q);
    r = search(node->right, p , q);
    if ((l && r) || (cur && l) || (cur && r)) {
        gnode = node;
        return true;
    }
    return l || r || cur;
}

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    gnode = NULL;
    search(root, p->val, q->val);
    return gnode;
}
```