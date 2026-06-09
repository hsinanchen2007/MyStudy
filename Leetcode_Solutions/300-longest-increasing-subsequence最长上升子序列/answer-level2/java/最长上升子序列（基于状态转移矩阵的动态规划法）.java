比状态转移方程复杂度更高一些，但是矩阵的内容与官方的方法二“贪心+二分查找”完美契合，算是另一种角度

```java
/**
 * 思路 1：动态规划法 (状态转移矩阵)
 *
 * 假设使用 f(i, max, len) 构造递归树，其中 i 表示将要决策第 i 个数字是否纳入上升子序列中，max 表示当前上升子序列的最大值，
 * len 表示当前上升子序列的长度。
 *
 * 那么递归树应该从 f(0, 0, 0) 结点开始，分叉为 f(1, 0, 0) 结点和 f(1, nums[0], 1) 结点，然后再继续分叉。
 *
 * 继续分叉的过程中，有如下几条规则：
 * 1. f(i, x, l) 决策 y 时，如果 y <= x，则只能分叉出 f(i+1, x, l) 一个结点；
 * 2. f(i, x, l) 决策 y 时，如果 y > x，则能够分叉出 f(i+1, x, l) 结点和 f(i+1, y, l+1) 结点；
 *
 * 完成任意一次分叉后，相同层级 (i 相同) 的不同结点，如果长度相同 (len 相同)，那么只需要保留最大值 (max) 较小的结点，
 * 其余结点可以视为重复子问题。
 *
 * 因此可以设计一个状态转移矩阵 states，其中 states[i][len] = max，能够计算得到 len 最大可以达到多少。
 */
class Solution1 {
    /**
     * @param nums 无序的整数数组
     * @return 最长上升子序列的长度
     */
    public int lengthOfLIS(int[] nums) {
        if (0 == nums.length) return 0;
        int i, j, ans = 1, upgrade;
        // 状态转移矩阵，states[i][j] = k 表示存在 f(i, k, j) 状态结点
        int[][] states = new int[nums.length][nums.length+1];
        // 初始化第一行
        states[0][1] = nums[0];
        // 从第二行开始遍历数组中的数字
        for (i = 1; i < nums.length; i++) {
            // 查看是否能够用 y=nums[i] 更新状态 (i,j)，状态 (i,j)由：
            // 状态 x1 纳入 y 后产生的新状态和状态 x2 不纳入 y 后产生的新状态共同决定
            //
            // x1, x2
            // - ,(i,j)
            for (j = 1; j <= ans+1; j++) {
                // y > x1，x1 能够影响 (i,j)
                if (nums[i] > states[i-1][j-1]) {
                    // 状态 x2 不存在，x2 不能影响 (i,j)
                    if (states[i-1][j] == 0) {
                        // f(i, x1, l) -> f(i+1, y, l+1)
                        states[i][j] = nums[i];
                    }
                    // 状态 x2 存在，x2 能够影响 (i,j)
                    else {
                        // f(i, x1, l) -> f(i+1, y, l+1)  |
                        // f(i, x2, l) -> f(i+1, x2, l+1) -> f(i+1, min(y, x2), l+1)
                        states[i][j] = Math.min(states[i-1][j], nums[i]);
                    }
                }
                // y <= x1，x1 不能影响 (i,j)
                // f(i, x2, l) -> f(i+1, x2, l+1)
                else {
                    states[i][j] = states[i-1][j];
                }
            }
            // 子序列的长度增加了
            if (states[i][j-1] != 0) {
                ans++;
            }
        }
        return ans;
    }
}

```
