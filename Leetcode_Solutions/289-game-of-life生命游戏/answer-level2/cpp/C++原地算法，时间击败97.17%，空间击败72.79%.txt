- 矩阵的元素是同时改变的，也就是说不能用更新后的元素进行计算，但是原地算法又不能使用额外的空间存储更新后的元素，所以想到了用原矩阵同时保存原始数据和新数据。
- 为了同时保存两个数据，那么原来的0和1两个变量就不能满足要求了，由于一共有四种可能，活-活，活-死，死-活，死-死。所以使用四个标识符来记录信息。
- 活-死用2表示，死-活用-1表示。遍历一次矩阵后把所有2改成0，-1改成1。
- 代码如下：nei***our函数用于更新细胞状态
```
void gameOfLife(vector<vector<int>>& board) 
    {
        for(int i=0;i<board.size();i++)
            for(int j=0;j<board[0].size();j++)
                nei***our(board,i,j);
        for(int i=0;i<board.size();i++)
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j] == 2)
                    board[i][j] = 0;
                if(board[i][j] == -1)
                    board[i][j] = 1;
            }
        
    }
    void nei***our(vector<vector<int>>& board,int x,int y)
    {
        int live = 0;
        if(x>0)
        {
            if(board[x-1][y]>0)
                live++;
            if(y>0 && board[x-1][y-1]>0)
                live++;
            if(y<board[0].size()-1 && board[x-1][y+1]>0)
                live++; 
        }
        if(x<board.size()-1)
        {
            if(board[x+1][y]>0)
                live++;
            if(y>0 && board[x+1][y-1]>0)
                live++;
            if(y<board[0].size()-1 && board[x+1][y+1]>0)
                live++; 
        }
        if(y >0 && board[x][y-1]>0)
            live++;
        if(y < board[0].size()-1 && board[x][y+1]>0)
            live++;
        if(board[x][y] == 1)
        {
            if(live<2||live>3)
                board[x][y] = 2;
        }
        else if(live == 3)
            board[x][y] = -1;
    }
```