# 分析：
如果数组全是正数，只需要反复反转最小的数，分两种情况：
1. K 为奇数，等同于反转 1 次
2. K 为偶数，等同于反转 0 次

如果数组有一部分负数，也分两种情况：
1. 当负数个数 < 反转个数，把全部负数反转后，就成了上面全是正数的情况
2. 当负数个数 > 反转个数，只需要尽力反转最小的负数即可得到最大值

# 代码：
```java
public int largestSumAfterKNegations(int[] A, int K) {
        if (A == null || A.length == 0) {
            return 0;
        }
        int sum = 0;
        int minusSum = 0;
        Arrays.sort(A);
        for (int i = 0; i < A.length; i++) {
            sum += A[i];
            if (A[i] < 0) {
                minusSum++;
            }
        }
        // 如果没有负数，且 K 为奇数，反转最小的
        if (minusSum == 0 && (K & 1) == 1) {
            sum -= 2 * A[0];
        } else if (minusSum < K) {
            // 存在负数，完全反转后还需要继续反转
            int i = 0;
            for (; i < minusSum; i++) {
                sum -= 2 * A[i];
            }
            // 剩下的如果是奇数，挑选最小的反转
            if (((K - i) & 1) == 1) {
                int min = Math.min(Math.abs(A[i - 1]), A[i]);
                sum -= 2 * min;
            }
        } else if (minusSum >= K) {
            // 存在负数，且无法完全反转，只需要反转负数中最小的即可
            for (int i = 0; i < K; i++) {
                sum -= 2 * A[i];
            }
        }
        return sum;
    }
```
# 分析：
时间复杂度：$O(nlogn)$
空间复杂度：$O(1)$
