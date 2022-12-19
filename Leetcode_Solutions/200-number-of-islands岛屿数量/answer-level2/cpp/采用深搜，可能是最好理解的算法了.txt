### 解题思路
此处撰写解题思路
思路：
    1.利用bfs函数进行递归搜索（上下左右都得进行搜索），只要遇到1就把其变为0，直到遇不到1为止，这样就是一个岛屿
    2.在外遍历岛屿，遇到了1就调用bfs，这样bfs相当会“抹掉”一个完整的岛屿，count就自增，遍历完后输出count即可
### 代码

```cpp
class Solution {
public:
    void bfs(vector<vector<char>>& grid,int i,int j){
        if(i<0||i>=grid.size()||j<0||j>=grid[0].size())return;//越界结束
        if(grid[i][j]=='1'){
            grid[i][j]='0';
            bfs(grid,i-1,j);//上下左右都得遍历
            bfs(grid,i+1,j);
            bfs(grid,i,j-1);
            bfs(grid,i,j+1);
        }

    }
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        if(grid.size()==0)return 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]=='1'){
                    count++;
                    bfs(grid,i,j);
                }
            }
        }
        return count;
    }
};
```