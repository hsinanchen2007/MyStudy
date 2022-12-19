### 解题思路
二分模板
但是效率好像不是很高 
![HA~{V5M9QJE\]Q~{QLE)28NC.png](https://pic.leetcode-cn.com/da6b7c3654bfa2b1a41d72e3aead5b960809bb6ce247604c6d53dd3b307f7cc6-HA~%7BV5M9QJE%5DQ~%7BQLE\)28NC.png)


希望有大神帮忙优化一下 或者 给出更好的答案
### 代码

```java
class Solution {
    public int shipWithinDays(int[] weights, int D) {
       int sum = 0;
        int max = 0;
        for (int i = 0; i < weights.length; i++) {
            max = Math.max(max, weights[i]);
            sum += weights[i];
        }
        int left = max;
        int right = sum;

        while (left < right) {

            int mid = (left + right) >>> 1;
            int day = 1;
            int total = 0;
            for (int i = 0; i < weights.length; i++) {
                total += weights[i];
                if (total > mid) {
                    day++;
                    total = weights[i];
                }
            }
            if (day > D) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
}
```