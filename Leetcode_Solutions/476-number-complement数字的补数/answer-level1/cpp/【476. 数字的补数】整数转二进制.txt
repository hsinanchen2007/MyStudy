### 思路
问题转为整数转为二进制，对每位进行取反。

### 代码

```cpp
class Solution {
public:
    int findComplement(int num) {
        int res = 0, i = 0;        
        while (num) {
            int t = num % 2;
            res += (1 - t) * pow(2, i++);
            num /= 2;
        }
        return res;
    }
};
```