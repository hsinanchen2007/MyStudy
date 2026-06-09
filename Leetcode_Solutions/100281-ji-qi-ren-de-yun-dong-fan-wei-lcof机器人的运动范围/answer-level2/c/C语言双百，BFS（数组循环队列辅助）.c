
典型的BFS题目，从[0,0]开始，分别往上、下、左、右遍历，队列的代码这里就不贴了，用的是数组实现的循环队列。
如果能够满足条件（GetSum(x) + GetSum(y)) <= k），说明该坐标可达，计数加一，并置标记位。
![image.png](https://pic.leetcode-cn.com/8bfee1210928de8ac561a237ed1b86421f8d39214a39f9be66118b20e66a9d20-image.png)
```
int g_walkCnt;
int g_visited[MAX_SIZE][MAX_SIZE];

void Walk(int x, int y, int m, int n, int k){
    if (x >= 0 && y >= 0 && x < m && y < n && ((GetSum(x) + GetSum(y)) <= k) && (!g_visited[x][y])) {
        Node node = {x, y};
        EnQueue(&node);
        g_visited[x][y] = 1;
        g_walkCnt++;
    }
}

int Bfs(int m, int n, int k){
    Node *node = NULL;
    memset(g_visited, 0, sizeof(g_visited));
    /* 原点必然可达 */
    g_walkCnt = 1;
    g_visited[0][0] = 1;
    while (!IsEmpty()){
        node = DeQueue();
        Walk(node->x - 1, node->y, m, n, k);
        Walk(node->x + 1, node->y, m, n, k);
        Walk(node->x, node->y - 1, m, n, k);
        Walk(node->x, node->y + 1, m, n, k);
    }
    return g_walkCnt;
}

int movingCount(int m, int n, int k){
    Node start = {0, 0};
    EnQueue(&start);
    return Bfs(m, n, k);
}
```
