   首先对N行中的每一行进行探测，寻找该行中可以放置皇后的位置，具体方法是对该行的每一列进行探测，看是否可以放置皇后，如果可以，则在该列放置一个皇后，然后继续探测下一行的皇后位置。如果已经探测完所有的列都没有找到可以放置皇后的列，此时就应该回溯，把上一行皇后的位置往后移一列，如果上一行皇后移动后也找不到位置，则继续回溯直至某一行找到皇后的位置或回溯到第一行，如果第一行皇后也无法找到可以放置皇后的位置，则说明已经找到所有的解程序终止。如果该行已经是最后一行，则探测完该行后，如果找到放置皇后的位置，则说明找到一个结果，打印出来。但是此时并不能再此处结束程序，因为我们要找的是所有N皇后问题所有的解，此时应该清除该行的皇后，从当前放置皇后列数的下一列继续探测
```
class Solution {
public:
    bool isValid(int row,vector<int>col)    //判断改位置是否可以放置
    {
        for(int i=0;i<row;i++)
        {
            if((col[i]==col[row])||(col[i]-col[row]==row-i)||(col[i]-col[row]==i-row))
            return false;
        }
        return true;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>res;
        vector<string>board(n,string(n,'.'));
        vector<int>col(n+1,0);          //列数组col[i]表示皇后放在第i行的col[i]列
        int row=0;
        col[row]=0;
        while(1)
        {
            if(row<board.size()&&col[row]<board[0].size())
            {
                if(!isValid(row,col))
                {
                    col[row]++;         //该列不能放置，移动到下一列
                }
                else
                {
                    board[row][col[row]]='Q';
                    row++;              //该列可以防止移动到下一行
                    col[row]=0;         //新的一行从第0列开始判断
                }
            }
            else{
               if(row==board.size())    //移动的最后一行的下一行表示这种解法可行
                {
                    res.push_back(board);
                }
                row--;                  //回溯
                if(row<0) break;        
                board[row][col[row]]='.';   
                col[row]++;     
                }
        }
        
        
        return res;
    }
};
```
