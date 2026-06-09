### 解题思路
递归，别的就不说了，代码看看就明白了。
u1s1，递归还是比较常用的。
但是要注意，递归的精髓就是简单情况的判断，要考虑细致，哪些要考虑，哪些不要考虑。

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
bool Check(struct TreeNode* a,struct TreeNode* b)
{
    if(a==NULL&&b!=NULL||b==NULL&&a!=NULL) return false;
    else if(a==NULL&&b==NULL) return true;
    else
    {
        if(a->val==b->val) return Check(a->left,b->right)&&Check(a->right,b->left);
        else return false;
    }
}

bool isSymmetric(struct TreeNode* root){
    if(root!=NULL)
    return Check(root->left,root->right);
    else return true;
}
```