```
//用栈实现DFS

int maxDepth(TreeNode* root) {
    if(!root)return 0;
    stack<pair<TreeNode*,int>>s;
    TreeNode* p = root;
    int MaxDeep = 0;
    int Deep = 0;
    while(!s.empty()||p)
    {
        while(p)
        {
            s.push(pair<TreeNode*,int>(p,Deep+1));
            Deep++;
            p = p->left;
        }
        p = s.top().first;
        Deep = s.top().second;
        if(MaxDeep<Deep)MaxDeep = Deep;
        s.pop();
        p = p->right;
    }
    return MaxDeep;
}
```

```
//用递归实现DFS

int maxDepth(TreeNode* root) {
    if(!root)return 0;
        int L = maxDepth(root->left);
        int R = maxDepth(root->right);
        return L>R?L+1:R+1;
}
```

```
//用队列实现BFS

int maxDepth(TreeNode* root) {
    deque<TreeNode*>q;
    reeNode* p;
    if(!root)return 0;
    q.push_back(root);
    int deep = 0;
    while(!q.empty())
    {
        deep++;
        int amo = q.size();
        while(amo>0)
        {
            p = q.front();
            q.pop_front();
            if(p->left)q.push_back(p->left);
            if(p->right)q.push_back(p->right);
            amo--;
        }
    }
    return deep;
}
```

如有改进地方欢迎指正
