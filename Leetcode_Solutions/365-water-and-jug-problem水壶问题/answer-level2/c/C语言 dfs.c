### 解题思路
用bfs解，queue[MAX_SIZE][2] 记录x和y的值，visited[MAX_SIZE][MAX_SIZE] 标记是否已经访问
但是超出内存限制

改用dfs解，water表示可以得到的水量，这个water可能在x桶，可能在y桶。
在dfs中，两个桶都有倒满和清空两种情况，用 || 连起来

### 代码

```c
#define MAX_SIZE 1000000
bool dfs(int x, int y, int z, int water, int *visited)
{
    if (water < 0) {
        return false;
    }
    
    if (water == z || x + water == z || y + water == z) {
        return true;
    }
    
    if (visited[water] == 1) {
        return false;
    }
    visited[water] = 1;
    
    
    return dfs(x , y, z, x - water, visited) || dfs(x, y, z, y - water, visited) ||
           dfs(x , y, z, water - x, visited) || dfs(x, y, z, water - y, visited);
}

bool canMeasureWater(int x, int y, int z){
    if (x + y < z) {
        return false;
    }
    if (z == 0) {
        return true;
    }
   
    int *visited = (int *)calloc(MAX_SIZE, sizeof(int));
    
    return dfs(x, y, z, 0, visited);
}
```