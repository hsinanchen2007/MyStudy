
```
class Solution
{
public:
    //给定两棵树，判断是否完全一致
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p == NULL && q == NULL)
        {
            return true;
        }
        if (p == NULL || q == NULL)
        {
            return false;
        }
        if (p->val != q->val)
        {
            return false;
        }
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }

    bool isSubtree(TreeNode *s, TreeNode *t)
    {
        if(s == NULL)
        {
            return false;
        }
        return isSameTree(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
    }
};
```
