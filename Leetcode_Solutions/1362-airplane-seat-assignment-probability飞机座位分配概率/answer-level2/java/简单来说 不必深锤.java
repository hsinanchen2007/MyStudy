### 解题思路
就概率来说 乘客与座位之间的关系无非就是乘客坐到了座位上与乘客没坐到座位上，几率除了第一位乘客之外其实都是0.5的几率

### 代码

```java
class Solution {
    public double nthPersonGetsNthSeat(int n) {
       return n==1?1:0.5;
    }
}
```