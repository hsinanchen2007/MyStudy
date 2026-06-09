### 解题思路
深度优先搜索

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