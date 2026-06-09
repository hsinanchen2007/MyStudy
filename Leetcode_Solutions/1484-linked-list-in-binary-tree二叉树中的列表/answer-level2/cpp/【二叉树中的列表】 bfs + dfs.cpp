### 思路
1. 使用 bfs 找到起点
2. 使用 dfs 匹配

### 答题
```C++
bool dfs(ListNode* head, TreeNode* root)
{
    if (head == nullptr) return true;
    if (root == nullptr) return false;
    if (root->val != head->val) return false;
    return dfs(head->next, root->left) || dfs(head->next, root->right);
}

bool isSubPath(ListNode* head, TreeNode* root) 
{
    queue<TreeNode*> que;
    que.push(root);

    while (!que.empty())
    {
        auto q = que.front();
        que.pop();
        if (q == nullptr) continue;

        if (q->val == head->val)
        {
            if (dfs(head, q)) return true;
        }
        que.push(q->left);
        que.push(q->right);
    }
    return false;
}
```



### 致谢

感谢您的观看，希望对您有帮助，欢迎热烈的交流！  

[我的leetcode](https://github.com/AhJo53589/leetcode-cn)

