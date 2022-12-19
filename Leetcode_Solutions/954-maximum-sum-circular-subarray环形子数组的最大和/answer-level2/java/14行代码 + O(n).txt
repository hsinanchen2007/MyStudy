### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int maxSubarraySumCircular(int[] A) {
        int minimum = Integer.MAX_VALUE, minSum = 0;
        int maximum = Integer.MIN_VALUE, maxSum = 0;
        int sum = 0;
        for(int a : A) {
            minSum = Math.min(minSum + a, a);
            minimum = Math.min(minimum, minSum);
            maxSum = Math.max(maxSum + a, a);
            maximum = Math.max(maximum, maxSum);
            sum += a;
        }
        if(sum - minimum == 0) {
            return maximum;
        }
        return Math.max(maximum, sum - minimum);
    }
}
```