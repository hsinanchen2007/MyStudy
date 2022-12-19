**原理请看官方题解**

递归：
```
    bool isSymmetric(TreeNode* root) {
        return _isMirror(root, root);
    }

    bool _isMirror(TreeNode *t1, TreeNode *t2){
        if (!t1 && !t2) return true;
        if (!t1 || !t2) return false;
        if (t1->val != t2->val) return false;

        return _isMirror(t1->left, t2->right) && _isMirror(t1->right, t2->left);
    }
```

迭代：
```
bool isSymmetric(TreeNode* root) {
        if (!root) return true;

        queue<TreeNode *> q;
        q.push(root);
        q.push(root);
        while (!q.empty()){
            auto q1 = q.front();
            q.pop();
            auto q2 = q.front();
            q.pop();

            if (!q1 && !q2) continue;
            if (!q1 || !q2) return false;
            if (q1->val != q2->val) return false;

            q.push(q1->left);
            q.push(q2->right);
            q.push(q1->right);
            q.push(q2->left);
        }

        return true;
    }
```

