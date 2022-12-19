class Solution {
public:
    bool isMatch(string s, string p) {
        int Size_s = s.size();
        int Size_p = p.size();
        bool Result[Size_s+1][Size_p+1];
        if((Size_s == 0)&&(Size_p == 0))
        {
            return true;
        }
        int i, j;
        Result[0][0] = true;
        for(i = 1; i < Size_s; i++)
        {
            Result[i][0] = false;
        }
        for(j = 0; j < Size_p; j++)
        {
            Result[0][j+1] = false;
            if(p[j] == '*')
            {
                Result[0][j+1] = Result[0][j];
            }
        }
        for(i = 0; i < Size_s; i++)
        {
            for(j = 0; j <Size_p; j++)
            {
                if((s[i] == p[j])||(p[j] == '?'))
                {
                    Result[i+1][j+1] = Result[i][j];
                }
                else
                {
                    if(p[j] == '*')
                    {
                        Result[i+1][j+1] = Result[i][j+1] || Result[i][j] || Result[i+1][j];
                    }
                    else
                    {
                        Result[i+1][j+1] = false;
                    }
                }
            }
        }
        return Result[Size_s][Size_p];
    }
};