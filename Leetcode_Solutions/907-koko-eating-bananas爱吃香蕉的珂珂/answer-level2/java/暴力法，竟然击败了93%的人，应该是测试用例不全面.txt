### 解题思路

![image.png](https://pic.leetcode-cn.com/7b9a695355c91dc1397425716605b83d66e07055e3ad97cdc677e388ef524070-image.png)

### 代码

```java
class Solution {
    public int minEatingSpeed(int[] piles, int H) {
        long sum = 0;
        for (int p : piles) {
            sum += p;
        }
        long average = sum / H;
        if (average == 0) {
            average = 1;
        }
        for (; ; ) {
            int totalTime = 0;
            for (int p : piles) {
                totalTime += p % average == 0 ? p / average : p / average + 1;
            }
            if (totalTime <= H) {
                return (int) average;
            }
            average++;
        }
    }
}
```