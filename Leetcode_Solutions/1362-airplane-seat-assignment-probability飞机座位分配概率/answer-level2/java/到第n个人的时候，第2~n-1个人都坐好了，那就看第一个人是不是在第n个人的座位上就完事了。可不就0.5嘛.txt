### 解题思路
到第n个人的时候，第2~n-1个人都坐好了，那就看第一个人是不是在第n个人的座位上就完事了。可不就0.5嘛

### 代码

```java
class Solution {
    public double nthPersonGetsNthSeat(int n) {
        return n==1?1:0.5;
    }
}
```