### 解题思路
空间换时间的思路，用visited矩阵记录访问过的位置，初始沿着右侧遍历，碰到边缘（数组边界和visited节点）则改变方向，直到末端。

### 代码

```cpp
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) { 
        vector<int> res;
        if(matrix.empty()) return res;
        int row = 0, col = 0, m = matrix.size(), n = matrix[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, 0));
        int direc = 0; //0右 1下 2左 3上
        while(true){
            //访问当前位置
            res.push_back(matrix[row][col]);
            visited[row][col] = 1;
            //计算下一个位置
            if(direc == 0){ //右
                if(col < n-1 && !visited[row][col+1]){ //可以右移
                    col ++;
                    continue;
                }else{                              //不可右移，转向朝下
                    direc = 1;
                    if(row < m-1 && !visited[row+1][col]){    //可以下移
                        row ++;
                        continue;
                    }else{                          //下移也不行，说明到达末端
                        break;
                    }
                }
            }
            if(direc == 1){ //下
                if(row < m-1 && !visited[row+1][col]){ //可以下移
                    row ++;
                    continue;
                }else{                              //不可下移，转向朝左
                    direc = 2;
                    if(col > 0 && !visited[row][col-1]){    //可以左移
                        col --;
                        continue;
                    }else{                          //左移也不行，说明到达末端
                        break;
                    }
                }
            }
            if(direc == 2){ //左
                if(col > 0 && !visited[row][col-1]){ //可以左移
                    col --;
                    continue;
                }else{                              //不可左移，转向朝上
                    direc = 3;
                    if(row > 0 && !visited[row-1][col]){    //可以上移
                        row --;
                        continue;
                    }else{                          //上移也不行，说明到达末端
                        break;
                    }
                }
            }
            if(direc == 3){ //上
                if(row > 0 && !visited[row-1][col]){ //可以上移
                    row --;
                    continue;
                }else{                              //不可上移，转向朝右
                    direc = 0;
                    if(col < n-1 && !visited[row][col+1]){    //可以右移
                        col ++;
                        continue;
                    }else{                          //右移也不行，说明到达末端
                        break;
                    }
                }
            }
            
        }
        return res;
    }
};
```