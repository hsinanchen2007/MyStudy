```
class Solution {
public:
    string longestPrefix(string s) {
        if (s.size() < 2) {//如果小于2说明没有快乐前缀
           return "";
        }
        int n = s.size();
        vector<int> next(n+1, -1);
        next[0] = -1;
        next[1] = 0;
        int pos = 2;//当前所求next数组下标
        int cn = 0;//利用之前的next数组的值求当前的next数组的值
        while (pos <= n) {
            if (s[pos - 1] == s[cn]) {
                next[pos++] = ++cn;
            }
            else if (cn > 0) {//还能往前跳
                cn = next[cn];
            }
            else {//cn == 0 说明跳无可跳
                next[pos++] = 0;
            }
        }
        return s.substr(0, next[n]);
    }
};
```
