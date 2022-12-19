![捕获.PNG](https://pic.leetcode-cn.com/140174739013c0e27e41529d1c4f1a9c9b2e9ca27e723f887269ee5a12c9d714-%E6%8D%95%E8%8E%B7.PNG)
遍历一遍，过程中分别求出总和total，子数组最大和maxSum，子数组最小和minSum。环形子数组最大和如果不需要首尾相接的话即为maxSum,如果需要首尾相接，则等于total-minSum。因此最终环形子数组最大和即为maxSum和total-minSum中的较大值。另外需要考虑全为负数的情况，此时total-minSum=0,但是结果应该取maxSum。
```
class Solution {
    public int maxSubarraySumCircular(int[] A) {
        int n = A.length;
        int right = 0, maxSum = Integer.MIN_VALUE, minSum = Integer.MAX_VALUE, curMax = 0, curMin = 0, total = 0;
        while (right < n) {
            total += A[right];
            curMax += A[right];
            curMin += A[right];
            maxSum = Math.max(maxSum, curMax);
            minSum = Math.min(minSum, curMin);
            if (curMax <= 0) curMax = 0;
            if (curMin >= 0) curMin = 0;
            right++;
        }
        return minSum == total ? maxSum : Math.max(maxSum, total-minSum);
    }
}
```
