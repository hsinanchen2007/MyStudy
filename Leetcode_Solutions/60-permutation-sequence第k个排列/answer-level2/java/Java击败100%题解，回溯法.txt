- ![clipboard.png](https://pic.leetcode-cn.com/ef9d95afa765caa1c6e7034c58e29b01eb243540b570d6f0fa32f9c56b450b1c-clipboard.png)
根据大佬的解题思路优化而来：
```
class Solution {
    // 结束回溯标志
    private boolean isDone = false;

    // 记录序列位置
    private int pos = 0;

    // 阶乘字典表
    private static int[] FACTORIAL_DICT = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};

    public String getPermutation(int n, int k) {
        int[] seed = new int[n];
        for (int i = 1; i <= n; i ++) {
            seed[i - 1] = i;
        }
        backtrace(seed, n, k, 0);
        // 拼接结果字符串
        StringBuilder strBuilder = new StringBuilder();
        for (int num: seed) {
            strBuilder.append(num);
        }
        return strBuilder.toString();
    }

    private void backtrace(int[] seed, int n, int k, int level) {
        if (level == n) {
            pos ++;
            // 走到第K个序列，结束回溯
            if (pos == k) {
                isDone = true;
            }
            return;
        }
        // 关键优化点：子序列个数和已走过的序列数和小于K，直接增加序列个数，跳过回溯
        if (FACTORIAL_DICT[n - level] + pos < k) {
            pos += FACTORIAL_DICT[n - level];
            return;
        }

        for (int i = level; i < n; i ++) {
            // 将i下标数据插入level下标位置（由于初始序列一开始是按由小到大数据排列，所以每次回溯能保证值递增）
            moveForword(seed, level, i);
            backtrace(seed, n, k, level + 1);
            if (isDone) {
                return;
            }
            // 复位，level下标位置数据插入i下标位置
            moveBack(seed, level, i);
        }
    }

    private void moveForword(int[] arr, int t, int k) {
        int tmp = arr[k];
        for (int i = k - 1; i >= t; i --) {
            arr[i + 1] = arr[i];
        }
        arr[t] = tmp;
    }

    private void moveBack(int[] arr, int t, int k) {
        int tmp = arr[t];
        for (int i = t + 1; i <= k; i ++) {
            arr[i - 1] = arr[i];
        }
        arr[k] = tmp;
    }
}
```