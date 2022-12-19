### 1. 模拟求解
拿到这题后，最初的想法就是模拟橘子变坏的过程来求解。
使用额外的数组，一是保存上一轮结束时的所有橘子的状态，使得修改某一橘子状态时不会将其改变，二是额外数组比原数组大一圈，这样在判断橘子时，都可以访问它的四个正方向。

```cpp
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // 特殊情况
        bool f_1 = false, f_2 = false;
        for(int i = 0; i < grid.size(); ++i){
            for(int j = 0; j < grid[0].size(); ++j){
                if(grid[i][j] == 1){
                    f_1 = true;
                }
                if(grid[i][j] == 2){
                    f_2 = true;
                }
            }
        }
        if(f_1 == false) return 0;
        if(f_2 == false) return -1;
        
        // 复制数组，计数好橘子的数目
        int c_1 = 0;
        int nums[12][12] = {0};
        for(int i = 0; i < grid.size(); ++i){
            for(int j = 0; j < grid[0].size(); ++j){
                nums[i+1][j+1] = grid[i][j];
                if(grid[i][j] == 1) ++c_1;
            }
        }

        int time = 0;
        bool flag = true;
        while(c_1 > 0 && flag){
            flag = false;
            for(int i = 1; i <= grid.size(); ++i){
                for(int j = 1; j <= grid[0].size(); ++j){
                    if(grid[i-1][j-1] == 1){
                        if(nums[i-1][j] == 2 || nums[i][j-1] == 2 || 
                        nums[i][j+1] == 2 || nums[i+1][j] == 2){
                            grid[i-1][j-1] = 2;
                            --c_1;
                            flag = true;
                        }
                    }
                }
            }
            ++time;

            // 保存本轮结束后的状态
            for(int i = 0; i < grid.size(); ++i){
                for(int j = 0; j < grid[0].size(); ++j){
                    nums[i+1][j+1] = grid[i][j];
                }
            }
        }

        if(c_1 > 0) return -1;
        else return time;
    }
};
```

### 2. 广度搜索
广度搜索的方法很巧妙，开始并没有想到。
```cpp
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // 特殊情况判断
        bool f_1 = false, f_2 = false;
        for(int i = 0; i < grid.size(); ++i){
            for(int j = 0; j < grid[0].size(); ++j){
                if(grid[i][j] == 1) f_1 = true;
                if(grid[i][j] == 2) f_2 = true;
            }
        }
        if(f_1 == false) return 0;
        if(f_2 == false) return -1;
        
        // 复制数组，计数好橘子数目，并将坏橘子入队
        int c_1 = 0;
        int nums[12][12] = {0};
        queue<pair<int, int>> que;
        pair<int, int> pair1;
        for(int i = 0; i < grid.size(); ++i){
            for(int j = 0; j < grid[0].size(); ++j){
                nums[i+1][j+1] = grid[i][j];
                if(grid[i][j] == 1) ++c_1;
                if(grid[i][j] == 2){
                    pair1.first = i+1;
                    pair1.second = j+1;
                    que.push(pair1);
                }
            }
        }

        // 广度遍历计算最短路径
        int time = 0;
        int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while(!que.empty()){
            int n = que.size();
            for(int i = 0; i < n; ++i){
                pair1 = que.front();
                que.pop();
                for(int k = 0; k < 4; ++k){
                    int x = pair1.first + dir[k][0], y = pair1.second + dir[k][1];
                    if(nums[x][y] == 1){
                        --c_1;
                        nums[x][y] = 2;
                        que.push(pair<int, int>(x, y));
                    }
                }
            }
            ++time;
        }

        if(c_1 > 0) return -1;
        else return time - 1;
    }
};
```