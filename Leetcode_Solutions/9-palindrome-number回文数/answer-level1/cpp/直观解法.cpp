首先，负数肯定不是，先排除，其次就是求倒序后的值，最后，跟入参x比较，相等即为回文数，否则不是

### 代码

```cpp
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        
        int tmp = 0;
        int cur = x;
        long int ret = 0;
        while (cur) {
            tmp = cur % 10;
            ret = ret * 10 + tmp;
            cur /= 10;
        }

        return (ret == x) ? true : false;
    }
};
```