
解法一
时间复杂度：O(n)
空间复杂度：O(n)
```
class Solution {
    public int partitionDisjoint(int[] A) {
        int n = A.length;
        // 从0往后统计区间的最大值
        int[] leftMax = new int[n];
        // 从n-1往前统计区间内的最小值
        int[] rightMin = new int[n];
        leftMax[0] = A[0];
        rightMin[0] = A[n - 1];

        // 更新区间内的最大值和最小值
        for (int i = 1; i < n; i++) {
            leftMax[i] = Math.max(A[i], leftMax[i - 1]);
            rightMin[i] = Math.min(A[n - i - 1], rightMin[i - 1]);
        }

        for (int i = 0; i < n - 1; i++) {
            // 当左半部分的最大值小于右半部分的最小值时结束
            if (leftMax[i] <= rightMin[n - i - 2]) {
                return i + 1;
            }
        }
        return n;
    }
}
```

解法二
时间复杂度：O(n)
空间复杂度：O(1)
```
class Solution {
    public int partitionDisjoint(int[] A) {
        // 记录左边最大值
        int leftMax = A[0];
        // 记录当前最大值
        int currentMax = A[0];
        int count = 1;
        for (int i = 1; i < A.length; i++) {
            // 如果当前的数小于左边最大值
            if (A[i] < leftMax) {
                // 更新左边最大值和左半部分长度
                // 当前最大值肯定在 A[i] 前面，既然 A[i]已经统计进去了，那么 leftMax 也用 currentMax 更新
                leftMax = currentMax;
                count = i + 1;
            } else {
                // 更新当前最大值
                currentMax = Math.max(currentMax, A[i]);
            }
        }
        return count;
    }
}
```
[Github-LeetCode](https://github.com/hncboy/LeetCode)
