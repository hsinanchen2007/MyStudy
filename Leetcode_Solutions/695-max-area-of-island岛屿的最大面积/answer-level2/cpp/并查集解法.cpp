# 说明:  

添加一个size数组，对于节点x, size[parent[x]] 记录x所属组的大小，即岛屿大小。  
其他的与并查集基本算法一致，可参考  
[Leetcode-岛屿数量200](https://leetcode-cn.com/problems/number-of-islands/)

# 代码如下:  
`--------------------------------------------------------------`  

```c++
class Solution {
public:
    vector<int> parent, size;
    //统计最大size
    int maxSize = 0;
    //初始化
    void init(int n){
        parent = vector<int>(n, -1);
        size = vector<int>(n, 0);
    }
    int unionSearch(int x){
        if(x != parent[x]) parent[x] = unionSearch(parent[x]);
        return parent[x];
    }
    void join(int x, int y){
        int x_p = unionSearch(x);
        int y_p = unionSearch(y);
        if(x_p != y_p){
            parent[y_p] = x_p;
            size[x_p] += size[y_p];
        }
        maxSize = max(maxSize, size[x_p]);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        //初始化
        init(n*m);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int index = i * m + j;
                if(grid[i][j] == 1) {
                    //初始化parent 和 size数组
                    parent[index] = index;
                    size[index] = 1;
                }
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1) {
                    //如果有1则岛屿大小至少为1
                    maxSize = max(maxSize, 1);
                    int index = i * m + j;
                    //合并岛屿
                    if(i+1 < n && grid[i+1][j] == 1) join(index, index+m);
                    if(j+1 < m && grid[i][j+1] == 1) join(index, index+1);
                }
            }
        }
        return maxSize;
    }
};
```