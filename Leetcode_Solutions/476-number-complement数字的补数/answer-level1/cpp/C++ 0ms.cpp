### 解题思路
一位位对比并加上去

### 代码

```cpp
class Solution {
public:
    int findComplement(int num)
    {
        int res = 0;
        int n = 0;
        while (num)
        {
            res += !(num & 1) << n;
            num >>= 1;
            n++;
        }
        return res;
    }
};
```