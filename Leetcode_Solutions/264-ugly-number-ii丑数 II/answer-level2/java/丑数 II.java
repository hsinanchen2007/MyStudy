### 解题思路
第n个丑数，就是前n-1个丑数，或乘2，或乘3，或乘5的积最小值。当然不是所有的丑数都要遍历的。每个丑数都有乘2乘3乘5各一次机会，都用完了就可以不再遍历了。同时，必定有某个丑数还没乘过2，比这个丑数大的数也都可以不再遍历了。

### 代码

```java
class Solution {
    public int nthUglyNumber(int n) {
        if (n == 0) return 0;
        long[] numbers = new long[n];
        numbers[0] = 1;
        int[] factors = new int[n];
        factors[0] = 2;
        int begin = 0, end = 0;
        for (int i = 1; i < n; i++) {
            long min = Long.MAX_VALUE;
            int minIndex = 0;
            for (int j = begin; j <= end; j++) {
                long product = numbers[j] * factors[j];
                if (product < min) {
                    min = product;
                    minIndex = j;
                } else if (product == min) {
                    factors[j] = factors[j] * 2 - 1;
                }
            }
            numbers[i] = min;
            factors[i] = 2;
            factors[minIndex] = factors[minIndex] * 2 - 1;
            while (factors[begin] > 5) {
                begin++;
            }
            while (factors[end] > 2) {
                end++;
            }
        }
        return (int) numbers[n - 1];
    }
}
```