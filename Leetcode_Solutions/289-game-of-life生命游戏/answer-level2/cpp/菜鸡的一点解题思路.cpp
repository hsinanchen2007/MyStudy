### 解题思路
思路主要就是先把所有活细胞的坐标存起来，然后遍历这些活细胞，用这些活细胞去影响周围的细胞，然后过程中修改Board，记录每个细胞周围有多少活细胞。

本来想的是把活细胞周围的值都加1，表示这些细胞周围有1个活细胞，然后遍历完所有的活细胞之后board存储的就是当前这个位置的细胞周围有多少活细胞，比如值是3表示这个细胞周围有三个活细胞，因此更新后一定是活细胞，但是如果值是2就无法判断了，因为不知道这个细胞初始是活细胞还是死细胞。

所以后来就想用正负来区分细胞的初始状态，负值表示这个细胞之前是死的，正值表示活，因此在用活细胞影响周边细胞时，如果周边细胞为正值（表示初始为活）就+1，为负值或零就-1。

这样全部计算完后对细胞进行更新，更新后依然是活细胞的只有两种情况：
- 值为-3，表示本身是死细胞，但是周围有3个活细胞
- 值为3或4，表示本身是活细胞，但是周围有2或3个活细胞（因为活细胞初值为1）
将符合上述两种情况的位置置1，其他值全都置0就可以。

大致思路就是这样，不知道我有没有说清楚，如果有错误还请大家指出，我会改正。第一次认真写题解，如果大家觉得对您有一点帮助，请点个赞吧~
![image.png](https://pic.leetcode-cn.com/916062448b7ea95ee6d70a70688d54d1110d10d2335b3c5bc862b3e2c9ccf4e3-image.png)


### 代码

```cpp
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if(board.size()&&board[0].size()==0)    return;
        int m=board.size(),n=board[0].size();
        int dir_x[8]={-1,-1,-1,0,0,1,1,1};
        int dir_y[8]={-1,0,1,-1,1,-1,0,1};
        vector<pair<int,int>> live;
        //加入所有活细胞
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==1)
                    live.push_back({i,j});
            }
        }
        //计算每个细胞周围有多少活细胞
        for(int i=0;i<live.size();i++){
            for(int j=0;j<8;j++){
                int nxt_x=live[i].first+dir_x[j];
                int nxt_y=live[i].second+dir_y[j];
                if(nxt_x<0||nxt_x>=m||nxt_y<0||nxt_y>=n)
                    continue;
                //++和--主要是为了后续更新细胞时区分初始状态是活细胞还是死细胞
                if(board[nxt_x][nxt_y]<=0)
                    board[nxt_x][nxt_y]--;
                else
                    board[nxt_x][nxt_y]++;
            }
        }
        //更新细胞状态
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                //-3表示初始为死细胞但周围有3个活细胞
                //3和4表示初始为活细胞且周围有2或3个活细胞
                if(board[i][j]==-3||board[i][j]==3||board[i][j]==4)
                    board[i][j]=1;
                else
                    board[i][j]=0;
            }
        }
    }
};
```