### 解题思路
此处撰写解题思路

### 代码

```c
#define MAX 1000000
bool dfs(int x, int y, int z, int left, int* visited) {
    if (left > x+y || left < 0) return false;
    if (left == z) return true;
    if (visited[left] == 1) return false;
    visited[left] = 1;
    return  dfs(x, y, z, x+left, visited) || dfs(x, y, z, y+left, visited) || dfs(x, y, z, y-(x-left), visited) || dfs(x, y, z, x-(y-left), visited);
}
bool canMeasureWater(int x, int y, int z){
    int visited[x+y+1];
    memset(visited, 0, sizeof(visited));
    return dfs(x, y, z, 0, visited);
}
```