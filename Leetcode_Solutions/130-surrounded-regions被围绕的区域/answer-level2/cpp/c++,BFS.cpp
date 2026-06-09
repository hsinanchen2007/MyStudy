### 解题思路
此处撰写解题思路
思路：从边缘开始，如果这个边缘点是'O',就依次从这点开始进行BFS搜索。将其替换成另一个字符 ，所有搜索完成 后，剩下的O就是边缘的O不连通的点，将其替换为X.其他的Y替换 为O。
我看题解中用DFS的很多，由于我是搜索的leetcode上面按BFS标签做的，所以一直在考虑BFS。我之前是在循环中，每检查一个边缘点,如果这个点等于'O',，就调用一次BFS,但是执行第56个用例时
就会超时，后面优化了一下代码，将所有等于'O'边缘点的位置加入队列，调用一次BFS就可以了。
执行结果：
通过
显示详情
执行用时 :
32 ms
, 在所有 cpp 提交中击败了
91.16%
的用户
内存消耗 :
14.2 MB
, 在所有 cpp 提交中击败了
73.50%
的用户

### 代码

```cpp
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int row = board.size();
        if(row == 0) return ;
        int col = board[0].size();
        if(col == 0) return ;
        queue<pair<int, int>> q;
        
        for(int i = 0 ; i < row; i++){
            for(int j  = 0; j < col; j++){
                if((i == 0 || i == row-1 || j == 0 || j == col-1) && board[i][j] == 'O')
                    q.push({i,j});
            }
        }
        BFS(board, row, col, q);
        for(int i  = 0; i < row; i++)
        for(int j  = 0; j < col; j++)
        {
            if(board[i][j] == 'O')
                board[i][j] = 'X';
            if(board[i][j] == 'Y')
                board[i][j] = 'O';
        }
    }
    void BFS(vector<vector<char>>& board,  int &row, int &col, queue<pair<int, int>> q)
    {     
        while(!q.empty())
        {
            auto val = q.front();
            q.pop();      
            board[val.first][val.second] = 'Y';
            if(val.first > 0 && board[val.first-1][val.second] == 'O') q.push({val.first-1, val.second});
            if(val.first < row-1 && board[val.first+1][val.second] == 'O') q.push({val.first+1, val.second});
            if(val.second < col-1 && board[val.first][val.second+1] == 'O') q.push({val.first, val.second+1});
            if(val.second > 0 && board[val.first][val.second-1] == 'O') q.push({val.first, val.second-1});
        }
    }
};
```