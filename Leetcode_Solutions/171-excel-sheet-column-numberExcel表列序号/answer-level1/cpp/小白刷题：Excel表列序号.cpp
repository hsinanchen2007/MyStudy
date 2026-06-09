遍历字符串计算即可

先减后加，以免爆int范围

代码：
```
class Solution {
public:
    int titleToNumber(string s) {
        int len = s.length();
        int ans = 0;
        for(int i = 0 ; i < len ; i++)
            ans = 26 * ans - 64 + (int)s[i];
        return ans;
    }
};
```
