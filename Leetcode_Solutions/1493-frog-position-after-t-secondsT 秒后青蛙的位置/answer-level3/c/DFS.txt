# 解法1：DFS
## 算法描述
从起点开始使用DFS搜索，对任意点，青蛙到达终点的概率等于：
* 若还能继续跳，则prob = sum(下一条的概率)
* 若不能继续跳，包含没有能跳的点和时间耗尽，则prob = 1 cond target == pos； prob = 0 otherwise

## 复杂度分析
时间复杂度：O（nt）
空间复杂度：O（t+n）

## 提交结果
通过

## 参考代码
```
typedef struct
{
    int key;
    int to[100];
    int num;
    UT_hash_handle hh;
}HashNode;

double dfs(HashNode *head, int *visited, int pos, int t, int target)
{
    if (!t) {
        return pos == target ? 1 : 0;
    }

    HashNode *node;
    HASH_FIND_INT(head, &pos, node);
    if (!node) {
        return pos == target ? 1 : 0; 
    }
    
    double prob = 0;
    int num = 0;
    for (int i = 0; i < node->num; i++) {
        if (visited[node->to[i]]) {
            continue;
        }

        visited[node->to[i]] = 1;
        prob += dfs(head, visited, node->to[i], t-1, target);
        visited[node->to[i]] = 0;
        num++;
    }

    if(!num) {
        return pos == target ? 1 : 0; 
    }

    return prob / num;
}

double frogPosition(int n, int** edges, int edgesSize, int* edgesColSize, int t, int target){
    HashNode *head = NULL;
    for (int i = 0; i < edgesSize; i++) {
        HashNode *node;
        HASH_FIND_INT(head, &edges[i][0], node);
        if (!node) {
            node = malloc(sizeof(HashNode));
            node->key = edges[i][0];
            node->num = 0;
            HASH_ADD_INT(head, key, node);
        }

        node->to[node->num++] = edges[i][1];

        HASH_FIND_INT(head, &edges[i][1], node);
        if (!node) {
            node = malloc(sizeof(HashNode));
            node->key = edges[i][1];
            node->num = 0;
            HASH_ADD_INT(head, key, node);
        }

        node->to[node->num++] = edges[i][0];
    }

    int visited[n+1];
    memset(visited, 0, sizeof(visited));
    visited[1] = 1;
    return dfs(head, visited, 1, t, target);
}
```