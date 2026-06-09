[Leetcode-Java(200+题解，持续更新、欢迎star)](https://github.com/pphdsny/Leetcode-Java/blob/master/src/pp/arithmetic/leetcode/_494_findTargetSumWays.java)

```java
    /**
     * 解题思路：
     * 暴力解法：每一位有两种操作（+、-），深度遍历整个数组，得到满足条件的个数，时间复杂度O(2^n) {@link _494_findTargetSumWays#findTargetSumWays1(int[], int)}
     *
     * 优化解法：0-1背包问题改版
     * 1、求出背包中要取的总数和:
     *  假设取正数和P，负数和N，P-N = target
     *  两边同时加上 P+N ==> P+N+P-N = target + P+N（其中P+N=nums的总和）
     *  2*P = target+sum ==> P = (target+sum)/2（P就是要取得总和）
     * 2、dp[i]代表合成i有多少种方法，动态转移方程dp[i] += dp[i - num];
     *  dp[i]的总和 == 除了i以外所有可能性总和，举例：[n1,n2,n3]，dp[i]=dp[i-n1]+dp[i-n2]+dp[i-n3]
     *
     * @param nums
     * @param target
     * @return
     */
    public int findTargetSumWays(int[] nums, int target) {
        int sum = 0;

        for(int num : nums) {
            sum += num;
        }

        if(Math.abs(target) > sum || (sum + target) % 2 != 0) {
            return 0;
        }

        //1
        int P = (sum + target) / 2;
        int[] dp = new int[P + 1];
        dp[0] = 1;

        //2、
        for (int num : nums) {
            for (int i = P; i >= num; i--) {
                dp[i] += dp[i - num];
            }
        }

        return dp[P];
    }

    private int result = 0;

    /**
     * 暴力解法：
     * 执行用时 :673 ms, 在所有 Java 提交中击败了19.31%的用户
     * 内存消耗 :35.2 MB, 在所有 Java 提交中击败了81.70%的用户
     *
     * @param nums
     * @param S
     * @return
     */
    private int findTargetSumWays1(int[] nums, int S) {
        dfs(nums, S, 0, 0);
        return result;
    }

    private void dfs(int[] nums, int S, int index, int cS) {
        if (cS == S && index == nums.length) {
            result++;
            return;
        }
        if (index >= nums.length) {
            return;
        }
        //+
        dfs(nums, S, index + 1, cS + nums[index]);
        //-
        dfs(nums, S, index + 1, cS - nums[index]);
    }

```