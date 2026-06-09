### 解题思路
解题思路:
计算相邻两个1之间的距离，并且除以2，在求最大值，就是该题的答案。
采用双指针发比官方解题更好理解。

### 代码

```java
class Solution {
    public int maxDistToClosest(int[] seats) {
        int max = 0;
        int j = 0;
        int length = seats.length;
        // j是第一个1,i是第二个1，离最近的1的最大值其实就是两个1直接的距离除以2，但是有特殊情况，如果开头和结尾为0，那么这时候不用除以2.
        for (int i = 1; i < length; i++) {
            if (seats[i] == 1) {
                if (j == 0 && seats[j] == 0) {
                    max = Math.max(max, i - j);
                } else {
                    max = Math.max(max, (i - j) / 2);
                }
                // 把i赋值给j，找下一段
                j = i;
            } else if (i == length - 1) {
                max = Math.max(max, i - j);
            }
        }
        return max;
    }
}
```