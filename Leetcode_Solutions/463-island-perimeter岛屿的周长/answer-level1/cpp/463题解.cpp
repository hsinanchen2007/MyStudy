### 解题思路
在四周补0，方便判断，但效率不高

### 代码

```cpp
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int length=0;
        int x[4]={-1,0,1,0};
        int y[4]={0,1,0,-1};
        vector<vector<int>>newGrid;
        for(int i=0;i<grid.size()+2;i++){
            vector<int>temp;
            temp.push_back(0);
            newGrid.push_back(temp);
            if(i==0||i==grid.size()+1){
                for(int j=0;j<grid[0].size();j++){
                    newGrid[i].push_back(0);
                }
            }else{
                for(int j=0;j<grid[0].size();j++){
                    newGrid[i].push_back(grid[i-1][j]);
                }
                newGrid[i].push_back(0);
            }
        }
        for(int i=1;i<=grid.size();i++){
            for(int j=1;j<=grid[0].size();j++){
                if(newGrid[i][j]){
                    for(int a=0;a<4;a++){
                        if(!newGrid[i+x[a]][j+y[a]]){
                            length++;
                        }
                    }
                }
            }
        }
        return length;
    }
};
```