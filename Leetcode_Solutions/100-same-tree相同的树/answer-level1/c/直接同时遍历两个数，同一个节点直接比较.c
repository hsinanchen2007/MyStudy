### 解题思路
此处撰写解题思路
判断一个树是否相同要判断各个节点是否相同
那么直接同时遍历两个树，会同时获取到同一个节点，直接进行比对即可
只要有一点不同就结束遍历，否则递归到下一个节点，按照中序遍历


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


bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    if (!p && !q) return true;
    if ((p && !q) || (!p && q) || p->val != q->val) return false;
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}
```