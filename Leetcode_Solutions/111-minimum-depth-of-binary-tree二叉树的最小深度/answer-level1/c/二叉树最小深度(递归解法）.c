### 解题思路
在求二叉树最大深度的基础上将不平衡的二叉树，即出现极端情况，元素全部在左边或者在右边，例如[1,2]最小值为
2，但是仅仅修改原来代码的>号变为<号时会存在最小值为1的情况，此时需要增加条件来避免这种情况发生
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


int minDepth(struct TreeNode* root){
    int leftDepth=1,rightDepth=1;
    if(root==NULL)
        return 0;
    else
    {
        leftDepth+=minDepth(root->left);
        rightDepth+=minDepth(root->right);
    }
    if(root->left==NULL)//根节点的左子树为空
        return rightDepth;
    else if(root->right==NULL)//根节点右子树为空
        return leftDepth;
    else
        return leftDepth<rightDepth?leftDepth:rightDepth;
}
```

代码通俗易懂，不做详细解释！