```
class Solution {
public:
    string tictactoe(vector<string>& board) 
    {
        string result;
        if(JudgeRows(board, result) == true || JudgeCols(board, result)== true || 
        JudgePositiveDiagonal(board, result) == true || JudgeNegativeDiagonal(board, result) == true)
        {
                return result; 
        }
        else if(isExistSpce(board))
        {
            return "Pending";
        }
        else
        {
            return "Draw";
        }
    }

    bool isExistSpce(vector<string>board)
    {
        int BoardLength = board.size();
        for(int row = 0; row<BoardLength;++row)
        {
            for(int col = 0; col<BoardLength;++col){
                if(board[row][col] == ' ')
                {
                    return true;
                }
            }
        }
        return false;
    }

    bool JudgePositiveDiagonal(vector<string> board, string & result)
    {
        bool answer = true;
        int BoardLength = board.size();
        for(int i =0; i < BoardLength -1; ++i)
        {
            if(board[i][i]!=board[i + 1][i + 1])
            {
                answer = false;
                break;
            }
        }
        if(answer == true && board[0][0]!= ' ')
        {
            result = board[0][0];
            return true;
        }
        return false;
    }

    bool JudgeNegativeDiagonal(vector<string> board, string & result)
    { 
        bool answer = true;
        int BoardLength = board.size();
        for(int i = BoardLength -1;i >= 1;--i)
        {
            if(board[i][BoardLength - i - 1] != board[i - 1][BoardLength - i])
            {
                answer = false;
                break;
            }
        }
        if(answer == true && board[BoardLength-1][0]!= ' ')
        {
            result = board[BoardLength-1][0];
            return true;
        }
        return false;
    }

    bool JudgeCols(vector<string> board, string & result)
    {
        bool answer;
        int BoardLength = board.size();
        for(int col = 0; col < BoardLength; ++col){
            int row = 0;
            answer = true;
            while(row + 1 < BoardLength)
            {
                if( board[row][col] != board[row+1][col])
                {
                    answer= false;
                    break;
                }
                ++row;
            }
            if(answer==true && board[0][col]!= ' ')
            {
                result = board[0][col];
                return true;
            }
        }
        return false;
    }

    bool JudgeRows(vector<string> board, string & result)
    {
        bool answer;
        int BoardLength = board.size();
        for(int row = 0;row < BoardLength; ++row)
        {
            int col = 0;
            answer = true;
            while(col + 1 < BoardLength)
            {
                if(board[row][col] != board[row][col + 1])
                {
                    answer = false;
                    break;
                }
                ++col;
            }
            if(answer==true && board[row][0]!= ' ')
            {
                result = board[row][0];
                return true;
            }
        }
        return false;
    }
};
```
