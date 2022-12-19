### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int reverse(int x) {

        int n = x;
        long ans = 0;
        while (n) {
            ans = ans * 10 + n % 10;
            n /= 10;
        }

        ans = n < 0 ? -ans : ans;
        return (ans > INT_MAX || ans < INT_MIN) ? 0 : ans;
    }
};
```