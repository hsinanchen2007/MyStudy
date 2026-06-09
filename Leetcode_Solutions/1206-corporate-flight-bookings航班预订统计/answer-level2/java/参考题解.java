### 解题思路

直接遍历数组，上车和下车其实是不冲突的。所有bookings[i][0]-1的时候都是上车，做加法；所有bookings[i][1]的时候都是下车，做减法就好了。太巧妙了。

1. new int[]为每一个航班初始化计数
2. 遍历bookings，把每个booking的booking[2]（预订航班数）分别加给： 从booking[0] 到 booking[1] 的航班
3. 返回计数结果
参考题解：https://leetcode-cn.com/problems/corporate-flight-bookings/solution/hang-ban-yu-ding-tong-ji-java-by-huangzhouwu/
### 代码

```java
class Solution {
    public int[] corpFlightBookings(int[][] bookings, int n) {
        int[] counters = new int[n];
        for (int[] booking : bookings) {
            counters[booking[0] - 1] += booking[2];
            if (booking[1] < n) {
                counters[booking[1]] -= booking[2];
            }
        }
        for (int i = 1; i < n; ++i) {
            counters[i] += counters[i - 1];
        }
        return counters;
    }
}
```