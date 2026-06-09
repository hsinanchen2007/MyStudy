### 解题思路
https://leetcode-cn.com/problems/integer-break/solution/zheng-shu-chai-fen-shu-xue-fang-fa-han-wan-zheng-t/

### 代码

```cpp
class Solution {
public:
    int integerBreak(int n) {
        if(n <= 3) return n-1;
        else if(n%3 == 0) return pow(3,n/3);
        else if(n%3 == 1) return 4*pow(3,n/3-1);
        else return 2*pow(3,n/3);
    }
};
```