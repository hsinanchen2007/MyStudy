```cpp
class Solution {
public:
    string compressString(string S) {
        if(S.empty()) return S;

        string ans = "";
        int cnt = 0;
        char tmp = S[0];
        for(auto ch:S){
            if(ch == tmp) ++cnt;
            else{
                ans += tmp + to_string(cnt);
                cnt = 1;
                tmp = ch;
            }
        }
        ans += tmp + to_string(cnt);

        return ans.size() < S.size() ? ans : S;
    }
};
```