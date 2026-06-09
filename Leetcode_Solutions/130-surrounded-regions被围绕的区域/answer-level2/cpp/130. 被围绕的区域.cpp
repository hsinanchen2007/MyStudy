### 解题思路
与外围O相连的所有O属于一个分量，先改成A；剩余的O即被围住的区域。
执行用时 :48 ms, 在所有 C++ 提交中击败了31.60%的用户
内存消耗 :13.2 MB, 在所有 C++ 提交中击败了100.00%的用户
### 代码

```cpp
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.size()==0) return;
        int n=board[0].size();
        int m=board.size();
        
        //搜索第一行
        int x=0;
        for(int y=0;y<n;y++)
        {
            if(board[x][y]=='O') change(board,x,y,m,n);
        }
        //搜索最后一行
        x=m-1;
        for(int y=0;y<n;y++)
        {
            if(board[x][y]=='O') change(board,x,y,m,n);
        }
        //搜索第一列
        int y=0;
        for(int x=1;x<m-1;x++)
        {
            if(board[x][y]=='O') change(board,x,y,m,n);
        }
        //搜索最后一列
        y=n-1;
        for(int x=1;x<m-1;x++)
        {
            if(board[x][y]=='O') change(board,x,y,m,n);
        }
        //把所有A转换成O,所有O转成X
        for(int x=0;x<m;x++)
        {
            for(int y=0;y<n;y++)
            {                
                if(board[x][y]=='O') board[x][y]='X';
                if(board[x][y]=='A') board[x][y]='O';
            }
        }

    }
    //对于每个在外围区域内的O向四周扩展搜索，遇O变A且递归，遇X停止
    void change(vector<vector<char>>& board,int x, int y,int m,int n)
    {
        board[x][y]='A';        
        int x1=x-1;
        int x2=x+1;
        int y1=y-1;
        int y2=y+1;
        
        
        if(x1>=0&&x1<m&&board[x1][y]=='O') change(board,x1,y,m,n);
        if(x2>=0&&x2<m&&board[x2][y]=='O') change(board,x2,y,m,n);
        if(y1>=0&&y1<n&&board[x][y1]=='O') change(board,x,y1,m,n);
        if(y2>=0&&y2<n&&board[x][y2]=='O') change(board,x,y2,m,n);
        
    }

};
```