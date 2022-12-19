```
class Solution {
public:
    set<int> row[9], col[9], box[9];
    vector<vector<int>> empty;  // 数独中未填数据下标
    void solveSudoku(vector<vector<char>>& board) {
        // 最直观做法是回溯法
        int cnt=0;
        for(int i=0; i<board.size(); i++)
            for(int j=0; j<board[0].size(); j++)
            {   if(board[i][j]=='.')  // 存储未解位置
                {    
                    vector<int> x={i, j};
                    empty.push_back(x);
                    cnt++;
                }
                else  // 记录初始已填充位置的状态
                {
                    int tmp=board[i][j]-'0';
                    row[i].insert(tmp);
                    col[j].insert(tmp);
                    box[i/3*3+j/3].insert(tmp);
                }    
            }
        backtrack(0, board);
    }
    bool backtrack(int index, vector<vector<char>>& board)  // 回溯算法
    {
        if(index==empty.size())
            return true;
        int i=empty[index][0], j=empty[index][1];
        for(int k=1; k<10; k++)  // 逐个尝试
        {
            if(!(row[i].count(k)||col[j].count(k)||box[i/3*3+j/3].count(k)))  // 行列，子数独均没有k
            {
                board[i][j]=k+'0';
                row[i].insert(k);
                col[j].insert(k);
                box[i/3*3+j/3].insert(k);
                if(!backtrack(index+1, board))  // 继续填下一个，若不合法，则回溯
                {
                    board[i][j]='.';
                    row[i].erase(k);
                    col[j].erase(k);
                    box[i/3*3+j/3].erase(k); 
                }
                else  // 此句只有最后一个数都成功填入才会触发
                    return true;
            }
        }
        return false;  // 循环完则冲突，不合法           
    }
};
```
