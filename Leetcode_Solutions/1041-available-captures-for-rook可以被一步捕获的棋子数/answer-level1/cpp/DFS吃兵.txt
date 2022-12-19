### 解题思路
第一想法是暴力循环但是感觉代码太多，就用了dfs代码应该较短（口糊）。dfs四个方向判断是否有兵加几个判断就行。
### 代码

```cpp
class Solution {
public:
    int dfs(vector<vector<char>>& board, int i, int j, char jl) {
        if(jl=='N') i--;
        else if(jl=='S') i++;
        else if(jl=='W') j--;
        else j++;
        if(i==-1 || i==8 || j==-1 || j==8) return 0;
        else if(board[i][j]=='B') return 0;
        else if(board[i][j] == 'p') return 1;
        else return dfs(board, i, j, jl);
    }
    int numRookCaptures(vector<vector<char>>& board) {
        int mkR, mkC;
        bool flag = true;
        for(int i = 0; i < 8 && flag; i++) {
            for(int j = 0; j < 8 && flag; j++) {
                if(board[i][j] == 'R') {
                    mkR = i;
                    mkC = j;
                    flag = false;
                }
            }
        }
        int ans = 0;
        ans += dfs(board, mkR, mkC, 'N');
        ans += dfs(board, mkR, mkC, 'S');
        ans += dfs(board, mkR, mkC, 'W');
        ans += dfs(board, mkR, mkC, 'E');
        return ans;
    }
};
```