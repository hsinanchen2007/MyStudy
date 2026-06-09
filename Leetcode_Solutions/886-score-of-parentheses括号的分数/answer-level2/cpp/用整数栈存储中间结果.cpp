```
class Solution {
public:
    int scoreOfParentheses(string S) {
        int res = 0;
        vector<int> strs;
        for(int i = 0; i < S.length(); ++i)
        {
            
            if(S[i] == '(')
            {
                // 为了能判别score属于哪一段括号，用-1来标识左括号位置
                strs.push_back(-1);
            }
            else
            {
                int re = 0;
                while(strs.back() != -1)
                {
                    re += strs.back();
                    strs.pop_back();
                }
                strs.pop_back();
                strs.push_back((re==0)?1:re*2);
            }
        }
        for(auto i:strs)
        {
            res += i;
        }
        return res;
    }
};
```
