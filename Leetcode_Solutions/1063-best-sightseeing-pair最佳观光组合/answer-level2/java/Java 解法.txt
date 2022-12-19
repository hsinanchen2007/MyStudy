从题目可知所求得分为等式 target = A[i] + A[j] + i - j 的最大值。

移动参数可得 target = A[i] + i + A[j] - j。

由于数组的值和下标都是固定的，对数组中每个值来说，A[i] + i 和 A[j] - j都是固定的。


使用 max 记录当前下标的最大值， preMax 记录当前下标前面范围的最大值。
从左往右遍历，对比 max 与 preMax + A[i] - i 更新新的 max。
然后对比 preMax 与 A[i] + i 更新新的 preMax。

```
public int maxScoreSightseeingPair(int[] A) {
    if(A == null || A.length == 0) {
        return 0;
    }

    int max = 0;
    int preMax = A[0] + 0;
    for (int i = 1, length = A.length; i < length; i++) {
        max = Math.max(max, preMax + A[i] - i);
        preMax = Math.max(preMax, A[i] + i);
    }
    return max;
}
```
