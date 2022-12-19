# 方法一 递归算法

```c++ []
int maxDepth(Node* root) {
    if (!root) return 0;
    int m = 0;
    for (Node* it : root->children) 
        m = max(m, maxDepth(it));
    return ++m;
}
```

# 方法二 DFS迭代

```c++ []
int maxDepth(Node* root) {
    if (!root) return 0;
    stack<pair<Node*,int>>stack;
    stack.push(pair<Node*, int>(root,1));
    int max_depth = 0;
    while (!stack.empty()) {
        Node* node = stack.top().first;
        int depth = stack.top().second;
        stack.pop();
        for (Node* it : node->children)
            stack.push(pair<Node*, int>(it, depth + 1));
        max_depth = max(max_depth, depth);
    }
    return max_depth;
}
```

# 方法三 BFS迭代

```c++ []
int maxDepth(Node* root) {
    if (!root) return 0;
    queue<Node*>queue;
    queue.push(root);
    int max_depth = 0;
    while (!queue.empty()) {
        max_depth++;			
        for (int size = queue.size(); size; size--) {
            Node* curr = queue.front(); queue.pop();
            for (Node* it : curr->children)
                queue.push(it);
        }
    }
    return max_depth;
}
```

欢迎优化与交流
