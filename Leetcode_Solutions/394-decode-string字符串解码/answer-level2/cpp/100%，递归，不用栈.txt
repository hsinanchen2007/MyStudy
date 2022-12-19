
```cpp
class Solution {
public:
    string decodeString(string s) {
        string res;
        int n = s.size(),l=0, r=0;
        // cnt用来记录目前访问到的左括号数与右括号之差，若为0，说明在括号之外
        int cnt = 0, tms = 0;
        for (int i = 0; i < n; i++){
            // 若是'['
            if (s[i]=='[') {
                if (cnt==0) l = i; // 记录第一次出现的括号s[l]
                cnt++;
            }
            // 若是']'
            else if (s[i]==']'){
                cnt--;
                if (cnt==0) { // s[r]是与s[l]对应的']':
                    r = i;
                    string t = decodeString(s.substr(l+1,r-l-1));
                    for (int j = 0; j < tms; j++) res += t;
                    tms = 0;
                }  
            }
            // 若在括号外
            else if (cnt==0) {
                if (isdigit(s[i])) tms = tms*10 + (s[i]-'0');
                else res += s[i];
            }
        }

        return res;
    }
};
```
