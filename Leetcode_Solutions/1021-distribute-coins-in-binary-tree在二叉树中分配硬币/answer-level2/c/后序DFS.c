### 解题思路
---把 += 改成 = +，运行速度直接增加了一倍---

思路就是一个后序遍历，我们先从所有的叶子节点开始，如果节点>1就把多的给他的父节点，<1就把少的给父节点，（但计数只加绝对值）最后就能都变成1了

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



int distributeCoins(struct TreeNode* root){
    int num=0;
    struct TreeNode pre;
    pre.left = root;
    void DFS(struct TreeNode*rt,struct TreeNode *par){
        if (!rt)
            return;
        DFS(rt->left,rt);
        DFS(rt->right,rt);
        num += (rt->val-1)>0?(rt->val-1):(1-rt->val);
        par->val = par->val + rt->val - 1;

    }
    DFS(root,&pre);
    return num;
}
```