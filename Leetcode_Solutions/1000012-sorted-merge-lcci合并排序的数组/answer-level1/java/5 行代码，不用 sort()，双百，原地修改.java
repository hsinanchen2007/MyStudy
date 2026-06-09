![合并排序的数组.png](https://pic.leetcode-cn.com/aa4800e27b6db26ca701d9b5b5e25e20bfab9ee453e515502caa6d9359fa1a57-%E5%90%88%E5%B9%B6%E6%8E%92%E5%BA%8F%E7%9A%84%E6%95%B0%E7%BB%84.png){:width=400}

### 解题思路
需要比较 $m + n$ 个数的大小，所以先保证其中至少 $m$ 或 $n$ 个数比较完毕并放在正确位置，再考虑剩下的数。
注意 $m$ 和 $n$ 是未遍历的、有效的数字的个数，不是下标，作为下标要 $-1$ 。写的时候偷懒，可能有些地方可读性比较差。

### 代码

```java [-Java]
class Solution {
    public void merge(int[] A, int m, int[] B, int n) {
        // 先确保将其中一个数组中的数字遍历完
        while (m > 0 && n > 0) {
            // 对比选出较大的数放在 m + n - 1 的位置，并将选出此数的指针向前移动
            A[m + n - 1] = A[m - 1] > B[n - 1] ? A[m-- - 1] : B[n-- - 1];
        }
        // 剩下的数都比已经遍历过的数小
        // 如果 m 不为 0，则 A 没遍历完，都已经在 A 中不用再管
        // 如果 n 不为 0，则 B 没遍历完，直接全移到 A 中相同的位置
        while (n > 0) {
            A[n - 1] = B[n - 1];
            n--;
        }
    }

    // 测试一下
    public static void main(String[] args) {
        int[] A = new int[] {1, 2, 3, 0, 0, 0};
        int[] B = new int[] {2, 5, 6};
        new Solution().merge(A, 3, B, 3);
        for (int i = 0; i < A.length; i++)
            System.out.print(A[i] + ",");
    }
}
```