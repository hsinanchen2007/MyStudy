### 解题思路
先想怎么算所有叶子节点的和
再想怎么判断当前叶子节点是不是左叶子
特殊输入：空树、只有一个节点的树
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

int sum(struct TreeNode* Root,struct TreeNode* Pre)
{
    if(Root==0)return 0;

    if(Root->left==0&&Root->right==0)
        if(Pre->left==Root)
            return Root->val;
        else
            return 0;

    return sum(Root->left,Root)+sum(Root->right,Root);
}

int sumOfLeftLeaves(struct TreeNode* root){
    if(root==0||(root->left==0&&root->right==0))return 0;
    return sum(root,0);
}
```