执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :9.9 MB, 在所有 C++ 提交中击败了100.00%的用户
```
class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> ans;
        if (s.empty())
        {
            return ans;
        }
        string tmp = s;
        string::iterator it;
        for (it = tmp.begin(); it < tmp.end()-1; ++it)
        {
            if ( *it=='+' && *(it+1)=='+' )
            {
                *it = '-';
                *(it+1) = '-';
                ans.push_back(tmp);
                tmp = s;
            }
        }
        return ans;
    }
};
```
