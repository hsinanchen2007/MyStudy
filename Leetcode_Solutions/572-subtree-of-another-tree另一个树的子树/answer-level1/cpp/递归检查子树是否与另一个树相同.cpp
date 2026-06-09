```
class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(cmpTree(s, t))
        {
            return true;
        }
        if(s == NULL)
        {
            return false;
        }
        if(isSubtree(s->left, t))
        {
            return true;
        }
        if(isSubtree(s->right, t))
        {
            return true;
        }
        return false;
    }
    bool cmpTree(TreeNode*s1, TreeNode*s2)
    {
        if(s1 == NULL && s2 == NULL)
        {
            return true;
        }
        else if(s1 != NULL && s2 != NULL)
        {
            return (s1->val == s2->val) && cmpTree(s1->left, s2->left) && cmpTree(s1->right, s2->right);
        }
        else
        {
            return false;
        }
    }
};
```
