回文去除对称轴划分为两半。

- 左半部第一个不是a的修改成a
- 如果左半部全部是a,把字符串最后一位修改成b
    

```
class Solution {
public:
    string breakPalindrome(string p) {
        bool flag = false;
        for(int i = 0; i < p.size()/2; i++) {
            if ('a' != p[i]) {
                p[i] = 'a';
                flag = true;
                break;
            }
        }
        if (!flag) {
            p[p.size()-1] = 'b';
        }
        if (check(p)) {
            return "";
        }
        return p;
    }
    
    bool check(string s) {
        for(int i = 0; i < s.size() / 2; ++i) {
            if (s[i] != s[s.size()-1-i]) return false;
        }
        return true;
    }
};
```
