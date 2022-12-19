### 解题思路
1. 定义一个变量`direction`，当`direction`为0时往右走，为1时往下走，为2时往左走，为3时往上走
2. 每进入一个格子，将该格子的值加入结果数组`ans`中
2. 每次一个方向走到底，然后`direction = (direction+1) % 4 `换方向，继续走
3. 当用于记录结果的`ans`和方阵数一样多时，说明全部格子走完了。
4. 这里采用一个数组记录当前格子是否被访问过，另一种方法可以动态改变`row`和`col`的大小使得不走重复的格子

### 代码

```cpp
class Solution {
public:
    // 用于记录该格子是否被访问过
    vector<bool> vis;
    vector<int> ans;
    int row;
    int col;
    int direction = 0;
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty()) return ans;
        row = matrix.size();
        col = matrix[0].size();
        vis.assign(row * col, false);
        int direction = 0;
        int i = 0, j = 0;
        while(ans.size() < row *  col){
            if(direction == 0){
                while(true){
                    if(j >= col || vis[i*col+j]) break;
                    ans.push_back(matrix[i][j]);
                    vis[i*col+j] = true;
                    j++;
                }
                //换方向，进入下一个方向的目标格子
                j--;
                i++;
                direction  = (direction + 1) % 4;
            }
            
            if(direction == 1){
                while(true){
                    if(i >= row || vis[i*col+j] == true){
                        break;
                    }
                    ans.push_back(matrix[i][j]);
                    vis[i*col+j] = true;
                    i++;
                }
                i--;
                j--;
                direction  = (direction + 1) % 4;
            }
            if(direction == 2){
               while(true){
                    if(j < 0 || vis[i*col+j]) break;
                    ans.push_back(matrix[i][j]);
                    vis[i*col+j] = true;
                    j --;
                }
                j ++;
                i --;
                direction  = (direction + 1) % 4;
            }
            if(direction == 3){
                while(true){
                    if(i < 0 || vis[i*col+j]) break;
                    ans.push_back(matrix[i][j]);
                    vis[i*col+j] = true;
                    i --;
                }
                i++;
                j++;
                direction  = (direction + 1) % 4;
            }
        }
        return ans;
    }
};
```