### 解题思路
从最上一阶楼梯开始往下有两种走法，一种是走1阶一种是走2阶，以此类推，每阶楼梯都有两种走法，
n阶楼梯，设函数f(n)为走法总数，则f(n) = f(n-1) + f(n-2) (n>=3)
设置初始值走0阶有0种，走1阶有1种，走2阶有2种，再把f(n)用代码表示即可
### 代码

```cpp
class Solution {
public:
    int climbStairs(int n) {
        int s0 = 0;
        int s1 = 1;
        int s2 = 2;
        int sn;
        if(n == 0)
            return s0;
        else if(n == 1)
            return s1;
        else if(n == 2)
            return s2;
        else {
            for(int i = 2; i < n; i++) {
                sn = s1 + s2;
                s1 = s2;
                s2 = sn;
            }
            return sn;
        }
    }
};
```