### 解题思路
求有多少个因子5

### 代码

```cpp
class Solution {
public:
    int trailingZeroes(int n) {
        int res=0;
        while(n>0)
        {
            n/=5;
            res+=n;
        }
        return res;
    }
};
```