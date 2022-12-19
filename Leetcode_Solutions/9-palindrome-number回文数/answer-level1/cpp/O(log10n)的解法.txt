### 解题思路
比官方稍微慢一些。注意点：
溢出的判断

### 代码

```cpp
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
         int xx = 0;
         int x_o = x;
         while (x != 0) {
             int a = x % 10;
             if (xx > INT_MAX/10 || xx == INT_MAX/10 && a>7)
                return false;
             xx = 10*xx + a; 
             x /= 10;           
         }
         return x_o == xx;
    }
};
```