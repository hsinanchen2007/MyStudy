### 解题思路
一个比较简单的思路，每个细胞只有0,1状态，我们想要实现原地算法，只需要加入新的两种状态，2是要活，3是要死。在第一次循环时，让细胞变成中间状态（要死或者要活或者不变），然后计算时，都mod2就行了，刚好状态能对应上（要死和活是一组，要活和死是一组）。这样，第一次遍历完后，在循环一次将中间状态的细胞置成最终态就行了。

### 代码

```cpp
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        //3 is go to die
        //2 is go to alive
        for(int i = 0;i < board.size();i++)
            for(int j = 0;j < board[0].size();j++)
                SearchOne(board,i,j);

        //将2,3弄成正确的
        for(int i = 0;i < board.size();i++)
            for(int j = 0;j < board[0].size();j++)
            {
                if(board[i][j] == 2)
                {
                    board[i][j] = 1;
                    continue;
                }
                if(board[i][j] == 3)
                {
                    board[i][j] = 0;
                    continue;
                }
            }
    }

    void SearchOne(vector<vector<int>>& board,int i ,int j)
    {
        //cout<<"xxx: "<<i<<" yyy: "<<j<<endl;
        int r = board[i][j];
        int count = 0;
        count += i < 1?0: board[i - 1][j] % 2;
        //cout<<"i : "<<i - 1<<" j : "<<j<<" c : "<<count<<endl;
        count += (i < 1 || j < 1)?0: board[i - 1][j - 1] % 2;
        //cout<<"i : "<<i - 1<<" j : "<<j - 1<<" c : "<<count<<endl;
        count += (i < 1 || j >= board[0].size() - 1)?0: board[i - 1][j + 1] % 2;
        //cout<<"i : "<<i - 1<<" j : "<<j + 1<<" c : "<<count<<endl;
        count += j < 1?0: board[i][j - 1] % 2;
        //cout<<"i : "<<i<<" j : "<<j - 1<<" c : "<<count<<endl;
        count += j >= board[0].size() - 1?0: board[i][j + 1] % 2;
        //cout<<"i : "<<i<<" j : "<<j + 1<<" c : "<<count<<endl;
        count += i >= board.size() - 1?0: board[i + 1][j] % 2;
        //cout<<"i : "<<i + 1<<" j : "<<j<<" c : "<<count<<endl;
        count += (i >= board.size() - 1 || j < 1)?0: board[i + 1][j - 1] % 2;
        //cout<<"i : "<<i + 1<<" j : "<<j - 1<<" c : "<<count<<endl;
        count += (i >= board.size() - 1 || j >= board[0].size() - 1)?0: board[i + 1][j + 1] % 2;
        //cout<<"i : "<<i + 1<<" j : "<<j + 1<<" c : "<<count<<endl;
        if(r == 0 && count == 3)
        {
            r = 2;
        }
        else if(r == 1 && (count < 2 || count > 3))
        {
            r = 3;
        }
        board[i][j] = r;
    }
};
```