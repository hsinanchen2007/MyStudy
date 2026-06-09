```
class Solution {
public:
    string freqAlphabets(string s) {
        int cur, n = s.length();
        string ans = "";
        for(int i = n-1; i >= 0; i--) {
            if(s[i] == '#') {
                cur = (s[i-2] - '0') * 10 + s[i-1] - '0';
                i -= 2;
            } else {
                cur =  s[i] - '0';
            }
            ans = char(cur - 1 + 'a') + ans;
        }
        return ans;
    }
};
```
