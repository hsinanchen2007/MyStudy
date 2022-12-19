# 递归
```
class Solution {
public:
    bool isEqual(TreeNode* l, TreeNode* r)
    {
        if (!l || !r) return l == r;
        return (l->val == r->val) && isEqual(l->left, r->right) && isEqual(l->right, r->left);
    }

    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return isEqual(root->left, root->right);
    }
}
```


# 迭代
```
class Solution {
public:
    bool isSymmetric(TreeNode* root)
    {
        if (!root) return true;

        auto l = root->left;
        auto r = root->right;
        if (!l || !r) return l == r;
        std::stack<TreeNode*> s;  //用栈和队列都一样
        s.push(l);
        s.push(r);

        while(!s.empty())
        {
            auto i = s.top(); s.pop();
            auto j = s.top(); s.pop();
            
            if (!i && !j) continue;
            else if (!i || !j) return false;

            if (i->val != j->val) return false;
            s.push(i->left);
            s.push(j->right);
            s.push(i->right);
            s.push(j->left);
        }

        return true;
    }
}
```