```
class Solution {
public:
    int movesToChessboard(vector<vector<int>>& board) 
    {
        int n = board.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if((board[0][0]^board[0][j]^board[i][0]^board[i][j])==1)
                    return -1;
            }
        }
        int row=0,col=0;
        int cntrow=0,cntcol=0;
        for(int i=0;i<n;i++)
        {
            row+=board[0][i];
            col+=board[i][0];
            if(board[0][i]!=i%2) cntrow++; //01010...
            if(board[i][0]!=i%2) cntcol++; //01010...
        }
        if(row<n/2 || row>(n+1)/2) return -1;
        if(col<n/2 || col>(n+1)/2) return -1;
        int res=0;
        if(n%2==0)
        {
            res+=min(cntrow,n-cntrow);
            res+=min(cntcol,n-cntcol);
        }
        else
        {
            if(cntrow%2==1)
                cntrow = n-cntrow;
            if(cntcol%2==1)
                cntcol = n-cntcol;
            res=cntrow+cntcol;
        }
        return res/2;
    }
};
```
首先先上所有的代码，感觉是比较清晰的，然后一步步把代码的每一步用例子举出来，数学太差了，说实话很多也不会证明
```
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if((board[0][0]^board[0][j]^board[i][0]^board[i][j])==1)
                    return -1;
            }
        }
```
这一步就是验证任意的board的四角都必须要是这三种情况：四个0，四个1，两个0两个1.
因为board只能交换行和列，所以这四个角是绑定在一起的，如果不是这三个情况就会：
 
```
1x1
0x1
```
x表示任意的字符，第二行的x无论是0还是1都没法通过变化使他变成board。

后面代码的row, col 表示在某一行，某一列中1的个数是多少
cntrow, cntcol 表示某一行，某一列中错位的值的个数是多少
比如：
```
10011010 
```
row = 4;
变换为10101010 需要一次变换 cntrow = 2; cntrow/2 = 1 = transform time.
变换为01010101 需要三次变换 n-cntrow = 8-2 = 6; (n-cntrow)/2 = 3 = transform time
取最小值 

如果行数是奇数的话 就只有一种格式了
1011001 -> 1010101

行和列是等效的， 行变换成功后， 做列的是不影响行的结果的。


