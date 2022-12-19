### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int numDecodings(string &s) {
        if(s[0] == '0') return 0;
        int n = s.size();
        int a, b = 1, c;
        for(int i = 1; i <= n; i++) {
            c = 0;
            if(s[i - 1] != '0') c = b;
            if(i - 2 >= 0 && (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6'))) {
                c += a;
            }
            a = b;
            b = c;
        }
        return c;
    }
};
```