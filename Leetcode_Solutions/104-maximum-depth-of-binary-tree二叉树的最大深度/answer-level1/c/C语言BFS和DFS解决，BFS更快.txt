# **DFS**
代码简单， 执行 8 ms	7.7 MB
```
int TreeDepthDfs(struct TreeNode* root)
{
    if (root == NULL) {
        return 0;
    }

    int left = TreeDepthDfs(root->left) + 1;
    int right = TreeDepthDfs(root->right) + 1;

    return left >= right ? left : right;
}
```

# **BFS**
逐层遍历， 队列内存要开大点。  执行 4 ms	7.6 MB
```
#define MAX_NODE_NUM 10240
struct TreeNode *g_queue[MAX_NODE_NUM];
int TreeDepthBfs(struct TreeNode* root)
{
    int head = 0;
    int tail = 0;
    struct TreeNode *node = root;
    int deep = 0;
    int curtail;

    if (node == NULL) {
        return 0;
    }

    g_queue[tail++] = root;

    while (head < tail && tail < MAX_NODE_NUM) {
        deep++;
        curtail = tail;
        // 逐层遍历
        for (int i = head; i < curtail; i++) {
            node = g_queue[i];
            if (node->left != NULL && tail < MAX_NODE_NUM) {
                g_queue[tail++] = node->left;
            }
            if (node->right != NULL && tail < MAX_NODE_NUM) {
                g_queue[tail++] = node->right;
            }
        }
        head = curtail;
    }

    return deep;
}
```


