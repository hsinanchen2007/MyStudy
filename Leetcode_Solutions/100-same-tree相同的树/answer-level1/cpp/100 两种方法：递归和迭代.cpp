### 解题思路
方法一：递归
方法二：迭代--使用栈。
### 代码
```递归 []
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q)
            return true;
        if (!p || !q)
            return false;
        return p->val==q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
```
```迭代 []
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p==nullptr && q==nullptr)
            return true;
        if (p==nullptr || q==nullptr)
            return false;
        TreeNode *f, *s;
        stack<TreeNode*> unprocessedList;
        unprocessedList.push(p);
        unprocessedList.push(q);
        while (!unprocessedList.empty()) {
            f = unprocessedList.top();
            unprocessedList.pop();
            s = unprocessedList.top();    
            unprocessedList.pop();
            if (f->val != s->val)
                return false;
            if (f->left && s->left) { //f和s的左子树都不空
                unprocessedList.push(f->left);
                unprocessedList.push(s->left);
            }
            else if (f->left || s->left) //f和s的左子树一个空一个不空
                return false;
            if (f->right && s->right) { //f和s的右子树都不空
                unprocessedList.push(f->right);
                unprocessedList.push(s->right);
            }
            else if (f->right || s->right) //f和s的右子树一个空一个不空
                return false;
        }
        return true;
    }
};
```

