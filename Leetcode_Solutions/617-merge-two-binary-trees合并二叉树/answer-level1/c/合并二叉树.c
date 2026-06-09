### 解题思路
理解二叉树最简单的方法就是递归

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


struct TreeNode* mergeTrees(struct TreeNode* t1, struct TreeNode* t2){
    if(t1==0&&t2==0)
        return 0;
    else if(t1!=0&&t2!=0)
    {
        t1->val+=t2->val;
        t1->left=mergeTrees(t1->left,t2->left);
        t1->right=mergeTrees(t1->right,t2->right);
        return t1;
    }
    else if(t1==0&&t2!=0)
        return t2;
    else 
        return t1;
}
```