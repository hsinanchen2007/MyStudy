思路：
1.第一遍遍历将0的点改为-1，便于后面统计周围活细胞数量
2-1.第二遍遍历计算周围活细胞数量，如何计算？判断该点位置大小，若>=0&&<9，那么这个点原本是个活细胞，记录个数count
2-2.如果中心点原本是活细胞，更新该点值为周围活细胞数量count，若原本为死细胞更新为count+9
3.第三遍遍历，判断各点值若小于9，这点原本是活细胞，按活细胞处理，若大于等于9，若让该点值-9后等于3则复活否则仍为死细胞。
```c++ []
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int dir[8][2]={{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
        int n=board.size();
        if(n==0)    return ;
        int m=board[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!board[i][j])    board[i][j]=-1;
            } 
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int count=0;
                for(int k=0;k<8;k++)
                {
                    int nx=i+dir[k][0],ny=j+dir[k][1];
                    if(nx>=0&&nx<n&&ny>=0&&ny<m)
                    {
                        if(board[nx][ny]>=0&&board[nx][ny]<9)
                            count++;
                    }
                }
                board[i][j]= board[i][j]==1?count:count+9;
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]<9)
                {
                    if(board[i][j]<2||board[i][j]>3) board[i][j]=0;
                    else board[i][j]=1;
                }
                else
                {
                    if(board[i][j]-9==3)    board[i][j]=1;
                    else board[i][j]=0;
                }
            }
        }
    }
};
```
