### 解题思路
设计两个映射表：
1）原初0,1到目标0,1的映射
2）映射值到目标0,1的映射

![image.png](https://pic.leetcode-cn.com/a210ed6e202f6df5a2ac3164d20b6088e6f6dad84c4e3b90bdfb7ceda5817ac6-image.png)




### 代码

```cpp
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        // (0, 0) ==> 2
        // (0, 1) ==> 3
        // (1, 0) ==> 4
        // (1, 1) ==> 5
        vector<int> org = {0, 1, 0, 0, 1, 1};
        vector<int> cur = {-1, -1, 0, 1, 0, 1};
        vector<vector<int>> mp(2, vector<int>(9, 0));
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 9; j++){
                if(i == 0){
                    if(j == 3){
                        mp[i][j] = 3;
                    }else{
                        mp[i][j] = 2;
                    }
                }else{
                    if(j == 2 || j == 3){
                        mp[i][j] = 5;
                    }else{
                        mp[i][j] = 4;
                    }
                }
            }
        }
        int m = board.size();
        int n = board[0].size();
        vector<int> delta = {0, 1, 1, -1, -1, 1, 0, -1, 0};
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int tmp = 0;
                for(int k = 0; k < 8; k++){
                    int x = delta[k] + i;
                    int y = delta[k+1] + j;
                    if(x >= 0 && x < m && y >= 0 && y < n){
                        int val = board[x][y];
                        tmp += org[val];
                    }
                }
                // cout<<"i = "<<i<<", j = "<<j<<" : "<<tmp<<endl;
                int v = board[i][j];
                board[i][j] = mp[v][tmp];
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int val = board[i][j];
                board[i][j] = cur[val];
            }
        }
    }
};
```