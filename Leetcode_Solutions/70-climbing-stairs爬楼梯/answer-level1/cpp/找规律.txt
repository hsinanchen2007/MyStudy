### 解题思路
先找规律

### 代码

```cpp
class Solution {
public:
    int climbStairs(int n) {
        int i1 = 0;
        int i2 = 1;
        for(int i = 1;i<=n;i++)
        {
            int temp = i1 + i2;
            i1 = i2;
            i2 = temp;
        } 
        return i2;
    }
};
```