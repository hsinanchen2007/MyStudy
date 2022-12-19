```cpp
class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        vector<int> res;
        int len = S.size();

        int cnt = 10000;
        for(char ch:S){
            if(ch == C)cnt = 0;
            else ++cnt;
            res.emplace_back(cnt);
        }

        cnt = 10000;
        for(int i = len - 1;i >= 0;--i){
            if(S[i] == C)cnt = 0;
            else ++cnt;
            res[i] = min(res[i],cnt);
        }
        return res;
    }
};
```