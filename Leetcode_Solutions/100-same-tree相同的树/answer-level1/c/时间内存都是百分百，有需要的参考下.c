### 解题思路
此处撰写解题思路

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
    bool a,b;
if(p!=NULL&&q!=NULL)
{
if(p->val==q->val)
{
a=isSameTree(p->left,q->left);
b=isSameTree(p->right,q->right);
if(a==true&&b==true)
{
    return true;
}else return false;
}else return false;
}
else if(p==false&&q==false)
{
    return true;
}else return false;
return true;
}
```