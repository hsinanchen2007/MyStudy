### 解题思路
Game of Life

### 代码

```cpp
class Solution {
    int has_life(vector<vector<int>>& tmp, int i, int j){
        int m=tmp.size(), n=tmp[0].size(), cnt=0;
        int x[8]={-1,-1,-1,0,0,1,1,1};
        int y[8]={-1,0,1,-1,1,-1,0,1};
        for(int t=0;t<8;t++){
            int xp=i+x[t], yp=j+y[t];
            if(xp>=0 && xp<m && yp>=0 && yp<n) cnt+=tmp[xp][yp];
        }
        if(tmp[i][j]){
            if(cnt<2 || cnt>3) return 0;
            else return 1;
        }
        return cnt==3;
    }
public:
    void gameOfLife(vector<vector<int>>& board) {

        int m=board.size(), n=board[0].size();
        vector<vector<int>> tmps(m, vector<int>(n, 0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                tmps[i][j]=board[i][j];
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                board[i][j]=has_life(tmps, i, j);
            }
        }
    }
};


```