```
class Solution {
public:

    bool isSame(TreeNode* t1, TreeNode* t2)
    {
        if(t1 == NULL && t2 == NULL) return true;
        if((t1 == NULL && t2 != NULL) || (t1 != NULL && t2 == NULL) || (t1 != NULL && t2 != NULL && t1->val != t2->val))
            return false;
        return isSame(t1->left,t2->left) && isSame(t1->right,t2->right);
    }

    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(s == NULL)
        {
            if(t == NULL) 
                return true;
            else 
                return false;
        }
        bool flag = false;
        if(s->val == t->val) 
            flag = flag || isSame(s,t);

        flag = flag || isSubtree(s->left,t);
        flag = flag || isSubtree(s->right,t);

        return flag;
    }
};

```