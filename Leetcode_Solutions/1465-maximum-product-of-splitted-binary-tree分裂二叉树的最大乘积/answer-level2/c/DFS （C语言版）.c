### 解题思路
1.为了方便(防止重复计算)，需要将二叉树的每个父节点变成--此节点的value + 所有孩子节点的value-- 可以用后序遍历
2.然后遍历树，找出最大乘积即可

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
int BDFS(struct TreeNode *root){
    if (!root)
        return 0;
    root->val += BDFS(root->left) + BDFS(root->right);
    return root->val;
}

int maxProduct(struct TreeNode* root){
    long long current,best,all;
    all = BDFS(root);
    best = -100000;
    void DFS(struct TreeNode *rt){
        if (!rt)
            return;
        current = (all-(rt->val))*rt->val;
        if (current>best)
            best = current;
        DFS(rt->left);
        DFS(rt->right);
    }
    DFS(root);
    return best%1000000007;
}
```