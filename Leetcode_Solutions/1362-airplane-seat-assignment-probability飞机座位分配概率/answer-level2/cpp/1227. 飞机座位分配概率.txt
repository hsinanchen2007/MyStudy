换一种思路：
后面每一个人来了之后如果自己的座位上有人就把他赶走
所以2~n-1号就会对位入座。
1号就在1和n号之间以50的概率坐下。
```
class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        return n==1?1.0:0.5;
    }
};
```
