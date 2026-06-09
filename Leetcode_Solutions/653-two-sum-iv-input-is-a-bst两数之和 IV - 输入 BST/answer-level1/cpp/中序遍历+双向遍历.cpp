```
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        stack<TreeNode*> ls;
        stack<TreeNode*> rs;
        TreeNode* l = root, *r = root;
        l = nextLeft(ls, l);
        r = nextRight(rs, r);
        while(l != r)
        {
            if(l->val+r->val == k)
            {
                return true;
            }
            else if(l->val+r->val < k)
            {
                l = nextLeft(ls, l->right);
            }
            else
            {
                r = nextRight(rs, r->left);
            }
        }
        return false;
    }
    TreeNode* nextLeft(stack<TreeNode*>&ls, TreeNode*l)
    {
        if(ls.empty() && l == NULL)
            return NULL;
        while(l)
        {
            ls.push(l);
            l = l->left;
        }
        l = ls.top();
        ls.pop();
        return l;
    }
    TreeNode* nextRight(stack<TreeNode*>&rs, TreeNode*r)
    {
        if(rs.empty() && r == NULL)
            return NULL;
        while(r)
        {
            rs.push(r);
            r = r->right;
        }
        r = rs.top();
        rs.pop();
        return r;
    }
};
```
