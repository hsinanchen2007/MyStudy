### 解题思路
此问题是子数组最大和的变种。
可以把问题的解分为两种情况。
（1）解没有跨过A[n-1]到A[0]（原问题）。
（2）解跨过A[n-1]到A[0]。
第一种情况就是一维数组的最大子数组和问题 sum = Math.max(A[i], sum+A[i]); if (maxsum < sum) maxsum = sum;
第二种情况又可以分为两种情况
    （2.1）包含整个数组（A[0], …, A[n-1]） allsum=sum(A)
    （2.2）包含两个部分：从A[0]开始的一段（A[0], …, A[j]）（0<=j<n），以及以A[n-1]结尾的一段（A[i], …, A[n-1]）（j＜i＜n）
    （2.2）相当于从数组中删除一块（A[j+1], …, A[i-1]）。这一部分的和一定是负的，且是可能找到的子数组的和为负数且绝对值最大的(最小的)。
    （2.2） result= allsum - minsum 
最后，再取两种情况的最大值就可以了

### 代码

```java
class Solution {
    public int maxSubarraySumCircular(int[] A) {
        int n = A.length;
        long sum = 0;
        long maxsum = Integer.MIN_VALUE;
        // 求取非环型数组中最大子数组之和
        for (int i=0;i<n;i++) {
            sum = Math.max(A[i], sum+A[i]);
            if (maxsum < sum) maxsum = sum;
        }
        // 求取非环型数组中最小子数组之和 用总和减之，即可得跨边界的最大子数组之和
        sum = 0;
        long allsum = 0;
        long minsum = Integer.MAX_VALUE;
        int negcnt = 0;
        for (int i=0;i<n;i++) {
            if (A[i]<0) negcnt++;
            allsum += A[i];
            sum = Math.min(A[i], sum+A[i]);
            if (minsum > sum) minsum = sum;
        }
        if (negcnt == n) {
            return (int)maxsum;
        } else {
            return (int) Math.max(maxsum, allsum-minsum);
        }
    }
}
```