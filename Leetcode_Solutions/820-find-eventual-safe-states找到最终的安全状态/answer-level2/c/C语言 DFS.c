### 解题思路
参考官方题解 C语言版本
设置一个visited[]数组。值为0表示未访问  1表示已访问  2表示已访问且为安全状态

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool dfs(int cur, int *visited, int ** graph, int *graphColSize){
    if(visited[cur] == 1) return false; //若再次访问到1，则有环
    if(visited[cur] == 2) return true;  //若再次访问到2，则安全
    if(graphColSize[cur] == 0) return true;//若该点没有出度，则安全

    visited[cur] = 1;
    for(int i=0; i<graphColSize[cur]; i++){
        int node = graph[cur][i];
        if(!dfs(node, visited, graph, graphColSize))
            return false;
    }

    visited[cur] = 2;       //若遍历完了cur行的所有元素，仍未返回false，则安全
    return true;
}
int* eventualSafeNodes(int** graph, int graphSize, int* graphColSize, int* returnSize){
    if(graphSize == 0) return 0;
    /**visited数组三个取值：
     *  0:未访问  1:已访问  2:已访问且为安全状态  */
    int *visited = (int*)malloc(sizeof(int) * graphSize);
    memset(visited, 0, sizeof(int) * graphSize);
    int *res = (int*)malloc(sizeof(int) * graphSize);
    memset(res, 0, sizeof(int) * graphSize);

    *returnSize = 0;
    for(int i=0; i<graphSize; i++){
        if(dfs(i, visited, graph, graphColSize)){
            res[(*returnSize)++] = i;
        }
    }

    return res;
}
```