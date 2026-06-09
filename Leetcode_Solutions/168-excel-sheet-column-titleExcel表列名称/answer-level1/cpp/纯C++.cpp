### 解题思路
纯C++

### 代码

```cpp
class Solution {
public:
    string convertToTitle(int n) {
        string res = "";
        
        while (1 <= n)
        {
            n -= 1; // 每次减1
            res.push_back('A' + (n % 26));
            n /= 26;
        }

        reverse(res.begin(), res.end());
        return res;
    }
};
```