设计一个每个数都大于10的质数集，将1-9映射到该集内，如1映射到11,2映射到13，再开辟27个long大小的空间，用int会超过范围，分别储存行，列，方块的值
每遇到一个数，先判断该数除以对应的行值会不会产生余数，由于质数的性质，如果之前有这个数出现过，就不会产生余数，如果有余数就将行值乘以映射的质数。
列，方块同理，速度马马虎虎，下面贴代码
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int prime[]={1,11,13,17,19,23,29,31,37,41};
        long row[9]={1,1,1,1,1,1,1,1,1};
        long column[9]={1,1,1,1,1,1,1,1,1};
        long square[9]={1,1,1,1,1,1,1,1,1};
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]!='.')
                { 
                if(row[i]%prime[board[i][j]-48]==0)
                   return false;
                else
                    row[i]*=prime[board[i][j]-48];
                if(column[j]%prime[board[i][j]-48]==0)
                    return false;
                else
                    column[j]*=prime[board[i][j]-48];
                if(square[i/3*3+j/3]%prime[board[i][j]-48]==0)
                    return false;
                else
                    square[i/3*3+j/3]*=prime[board[i][j]-48];
                }
               
            }
        }
        return true;
    }
};