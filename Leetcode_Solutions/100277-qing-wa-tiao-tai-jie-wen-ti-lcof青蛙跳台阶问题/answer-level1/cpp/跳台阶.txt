### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int numWays(int n) {
        if(n == 0)
            return 1;
        if(n == 1)
            return 1;
        if(n == 2)
            return 2;
        int first = 1;
        int second = 2;
        int total = 0, mod = 1e9+07;
        for(int i = 3; i<=n;i++){
            total = (second+first)%mod;
            first = second;
            second = total;
        }
        return total;
    }
};
```