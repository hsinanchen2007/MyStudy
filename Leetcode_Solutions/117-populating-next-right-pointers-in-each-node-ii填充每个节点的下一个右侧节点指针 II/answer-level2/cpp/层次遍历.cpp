从层次遍历改变来 c++超过 99.63的用户时间，100%的用户内存消耗

```
Node *connect(Node *root) {
    queue<Node *> q;
    if (root == nullptr)
        return root;
    q.push(root);
    while (!q.empty()) {
        int len = q.size();

        for (int i = 0; i < len; i++) {
            Node *tmp = q.front();
            q.pop();
            if (i != len - 1)
                tmp->next = q.front();
            if (tmp->left)
                q.push(tmp->left);
            if (tmp->right)
                q.push(tmp->right);
        }
    }
    return root;
}
```
相同的办法可以解决 116 [ 填充每个节点的下一个右侧节点指针](https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node/submissions/)
改变很少的代码相同的思想可以解决 199 [二叉树的右视图](https://leetcode-cn.com/problems/binary-tree-right-side-view/comments/)
```
vector<int> rightSideView(TreeNode *root) {
    vector<int> res;
    queue<TreeNode *> q;
    if (root == nullptr)
        return res;
    q.push(root);
    while (!q.empty()) {
        int len = q.size();
        res.push_back(q.back()->val);
        for (int i = 0; i < len; i++) {
            TreeNode *tmp = q.front();
            q.pop();
            if (tmp->left)
                q.push(tmp->left);
            if (tmp->right)
                q.push(tmp->right);
        }
    }
    return res;
}
```
只需要一个队列的额外空间