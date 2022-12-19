此题与373, 378, 668, 719, 786题为同一类型题目，建议先**搞懂378题**，然后再来做此题。
下面假设你已经搞懂378题了。

这是我的[LeetCode分类题解](https://github.com/caipengbo/LeetCode)（每日更新, issue内有总结），和我一起每日刷题吧！

此题的重点是：
- 如何转化成378题那种 行和列都是排序的矩阵类型
- 如何记录 p 和 q

代码如下：

```Java
public int[] kthSmallestPrimeFraction(int[] A, int K) {
    // 因为分数是在(0,1)范围内，所以在此范围使用二分查找
    double lo = 0, hi = 1, mid;
    int p = 0, q = 1;
    int i, j;
    int count;
    // 因为是在小数内使用二分查找，无法像在整数范围内那样通过 mid+1和边界判断来终止循环
    // 所以此处根据count来结束循环
    while (true) {
        mid = (lo + hi) / 2;
        count = 0;
        p = 0;
        for (i = 0; i < A.length; i++) {
            j = 0;
            while (j < A.length-1-i && mid >= (double) A[i]/A[A.length-1-j]) {
                j++;
            }
            count += j;
            // 重点：p/q是比 mid小的数中的最大值(所有行)
            if (j > 0 && ((double)p/q) < ((double)A[i]/A[A.length-j])) {
                p = A[i];
                q = A[A.length-j];
            }
        }
        if (count > K) hi = mid;
        else if (count < K) lo = mid;
        else return new int[]{p, q};
    }
}

```
