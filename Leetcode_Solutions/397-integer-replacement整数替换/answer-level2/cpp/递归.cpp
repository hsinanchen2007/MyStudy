### 解题思路
根据提议，当n为偶数时，n/2为一次变换，返回次数为 1 + replace(n/2)
当n为奇数时，返回min(replace(n-1), replace(n+1))

### 代码

```cpp
class Solution {
public:
    int integerReplacement(int n) {
        if (n == 1) {
            return 0;
        }
        if (n == INT_MAX) {
            return 32;
        }
        if ((n & 1) == 0) {
            return 1 + integerReplacement(n/2);
        }
        
        return 1 + min(integerReplacement(n+1), integerReplacement(n-1));
    }
};
```