首先计算数组元素总和，由于数组元素总和可能很大，因此需要用`long`存储。
然后通过二分查找得到满足要求的最小值。初始状态`low`取`1`，`high`取数组元素总和。循环条件是`low < high`，每次循环取`mid`为`low`和`high`的均值，将`mid`作为除数计算，如果商之和大于阈值，显然除数过小，令`low = mid + 1`，如果商之和小于等于阈值，则除数大于等于满足要求的最小值，令`high = mid`。退出循环意味着`low == high`。由于题目保证一定有解，退出循环时的`low`和`high`的值就是满足要求的最小值。
```
class Solution {
    public int smallestDivisor(int[] nums, int threshold) {
        long arraySum = 0;
        for (int num : nums)
            arraySum += num;
        long low = 1, high = arraySum;
        while (low < high) {
            long mid = (high - low) / 2 + low;
            int sum = 0;
            for (int num : nums) {
                int quotient = (int) Math.ceil(num * 1.0 / mid);
                sum += quotient;
            }
            if (sum > threshold)
                low = mid + 1;
            else
                high = mid;
        }
        return (int) low;
    }
}
```

