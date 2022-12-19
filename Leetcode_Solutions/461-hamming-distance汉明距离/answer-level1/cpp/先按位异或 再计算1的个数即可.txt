### 解题思路
如题

### 代码

```cpp
class Solution {
public:
    int hammingDistance(int x, int y)
    {
        int cnt = 0;
        int z = x ^ y;
        while (z > 0)
        {
            cnt += z & 1;
            z >>= 1;
        }
        return cnt;
    }
};
```