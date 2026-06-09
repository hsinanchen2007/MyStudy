### 解题思路
既然是删掉零子树，那自然想到先写一个判断是否为零子树的函数，拿着这个函数，对树内每一个结点都遍历一遍，如果为零子树，直接把该结点设置为NULL。利用l递归遍历完整棵树，最后返回头结点就OK了

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



bool NotZero(struct TreeNode* root)
{
    if(!root)
        return false;
    if(root->val==0)
    {
        return (NotZero(root->left)||NotZero(root->right));
    }
    else
        return true;

}




struct TreeNode* pruneTree(struct TreeNode* root)
{
   if(!root)
		return root;
    if(!NotZero(root))
    {
        root=NULL;
        return root;
    }
	root->left=pruneTree (root->left);

	root->right=pruneTree (root->right);

    return root;

}
```