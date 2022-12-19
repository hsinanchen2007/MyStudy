
/* 统计各个字符的数量，‘R’和‘L’对比，‘U’和‘D’对比 */

class Solution {
public:
    bool judgeCircle(string moves) {
        
        int R_nums = 0;
        int L_nums = 0;
        int U_nums = 0;
        int D_nums = 0;
        
        for (int i=0; i<moves.length(); i++)
        {
            if (moves[i] == 'R')    R_nums++;
            if (moves[i] == 'L')    L_nums++;
            if (moves[i] == 'U')    U_nums++;
            if (moves[i] == 'D')    D_nums++;
        }
        
        if ((R_nums == L_nums)  && (U_nums == D_nums))
            return true;
        else
            return false;
    }
};

