### 解题思路
从后往前➕，最后把结果 reverse 一下

### 代码

```cpp
class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1;
        int j = b.size() - 1;
        int c = 0;
        string res;
        
        while (i >= 0 || j >= 0) {
            int ans = c;
            ans += (i >= 0 ? a[i--] - '0' : 0);
            ans += (j >= 0 ? b[j--] - '0' : 0);
            res += (ans % 2 ? '1' : '0');
            c = ans / 2;
        }
        
        if (c)
            res += '1';
        reverse(res.begin(), res.end());
        
        return res;
    }
};
```