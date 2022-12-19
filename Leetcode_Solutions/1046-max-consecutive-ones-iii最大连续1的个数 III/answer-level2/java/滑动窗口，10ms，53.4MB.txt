### 思路：
使用双指针 `left` 和 `right` 指代窗口的左右边界，移动 `right` 指针遍历整个数组，
同时维护一个变量 `max`，每次 `right` 移动计算一次当前的最大值。

分析：

分为以下几种情况：

1. 当 `A[right] = 1` 时，`left` 不变，`right` 继续移动
2. 当 `A[right] = 0` 时，
    1. `0` 的数量在 `K` 的范围内，`left` 不变，`right` 继续移动
    2. `0` 的数量 > `K`，    
        1. 当 `A[left] == 0` 时，即 `left` 指向了一个零，只需要 `left` 右移一格，就可以减少一个零
        2. 当 `A[left] == 1` 时，即此时窗口内包了 `K` 个零，需要先移动至下个零，再右移一格才能减少一个零

### 代码：
```
public int longestOnes(int[] A, int K) {
    int max = 0;
    for (int left = 0, right = 0; right < A.length; right++) {
        if (A[right] == 0) {
            if (K == 0) {
                while (A[left] == 1) {
                    left++;
                }
                left++;
            } else {
                K--;
            }
        }
        max = right - left + 1 > max ? right - left + 1 : max;
    }
    return max;
}
```
时间复杂度：$O(n)$

空间复杂度：$O(1)$