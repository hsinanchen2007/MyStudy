斐波那契数列求解题

代码：
```
class Solution {
public:
    int climbStairs(int n) {
        if(n == 1) return 1;
        else if(n == 2) return 2;
        int lastLast = 1, last = 2, res = 0;
        for(int i = 3; i <= n; i++){
            res = lastLast + last;
            lastLast = last;
            last = res;
        }
        return res;
    }
};
```
