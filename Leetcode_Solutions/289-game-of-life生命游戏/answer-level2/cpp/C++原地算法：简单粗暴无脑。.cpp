原地算法。简单粗暴无脑。
思路：统计board[i][j]周围原始1的个数，根据规则进行变化。
如果 原始为1变为0，则用-1记录，-1也就代表了该位置原始为1；
如果 原始为0变为1，则用2记录，2也就代表了该位置原始为0；
其他的保持不变。

则 原始1的个数，由不变得1 与 变化后的-1组成。
最后将变化后的-1变为0，2变为1。

```
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        for(int i=0;i<board.size();++i)
        {
            for(int j=0;j<board[i].size();++j)
            {
                int n=numOf1(board, i, j);
                change(board, i, j,  n);
            }
        }
        for(int i=0;i<board.size();++i)
        {
            for(int j=0;j<board[i].size();++j)
            {
                //将记数 2变为1 ，-1变为0
                if(board[i][j]==2)
                    board[i][j]=1;
                if(board[i][j]==-1)
                    board[i][j]=0; 
            }
        }

    }
    //b[i][j]的邻居中1的个数(-1的前身是1)，直接使用if 判断边界，简单粗暴无脑
    int numOf1(vector<vector<int>>& b, int i, int j) 
    {
        int n=0;
        if((-1<i-1)&&(i-1<b.size())&&(-1<j-1)&&(j-1<b[i-1].size())&&(b[i-1][j-1]==1||b[i-1][j-1]==-1))
            ++n;
        if((-1<i-1)&&(i-1<b.size())&&(-1<j)&&(j<b[i-1].size())&&(b[i-1][j]==1||b[i-1][j]==-1))
            ++n;
        if((-1<i-1)&&(i-1<b.size())&&(-1<j+1)&&(j+1<b[i-1].size())&&(b[i-1][j+1]==1||b[i-1][j+1]==-1))
            ++n;
        if((-1<i)&&(i<b.size())&&(-1<j-1)&&(j-1<b[i].size())&&(b[i][j-1]==1||b[i][j-1]==-1))
            ++n;
        if((-1<i)&&(i<b.size())&&(-1<j+1)&&(j+1<b[i].size())&&(b[i][j+1]==1||b[i][j+1]==-1))
            ++n;
        if((-1<i+1)&&(i+1<b.size())&&(-1<j-1)&&(j-1<b[i+1].size())&&(b[i+1][j-1]==1||b[i+1][j-1]==-1))
            ++n;
        if((-1<i+1)&&(i+1<b.size())&&(-1<j)&&(j<b[i+1].size())&&(b[i+1][j]==1||b[i+1][j]==-1))
            ++n;
        if((-1<i+1)&&(i+1<b.size())&&(-1<j+1)&&(j+1<b[i+1].size())&&(b[i+1][j+1]==1||b[i+1][j+1]==-1))
            ++n;    
        return n;                          
    }

    //根据原始状态 和 周围1的个数 进行状态更改，1->0:-1，原始1变为0，记为-1；0->1:2 原始0变为1，记为2
    void change(vector<vector<int>>& b, int i, int j, int n)
    {
        if(b[i][j]==1)
        {
            if(n<2 ||n>3)
            {
                b[i][j]=-1;
            }
        }
        else if(b[i][j]==0 &&n==3)
        {
            b[i][j]=2;
        }
    }
};
```

