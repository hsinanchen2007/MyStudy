刚开始学习dp 个人感觉是
1. 先找子问题 看是两侧 还是一侧
    这题是两侧 找出bi, bi+1, ..., bj所能得到的最大coins
2. 然后写出子问题的表达式 找状态转移方程
    我们假定最后戳的的气球是r, i <= r <= j 
    dp[i, j] = nums[r - 1] * nums[r] * nums[r + 1] + dp[i, r - 1] + dp[r + 1, j]
    因为r的取值范围是[i, j] 所以需要通过循环找出最大的

    其实这个问题还挺特别的 因为它的两侧需要虚拟气球(不能戳破的气球)
    所以需要先对数组修改 在其两侧增加1 这样才能保证原数组中所以气球都可以被戳破
    既然修改了原数组 我们的状态转移方程也需要修改了
    dp[i][j] = init[i] * init[r] * init[j] + dp[i][r] + dp[r][j]
    此时的i 和 j都是不会被戳破的气球 i + 1 到 j - 1才是真正的子问题。 
    需要注意的是dp[i][r - 1]变成了dp[i][r], 这是因为我们最后才戳破r 所以在这个子问题的子问题中 r也是边界值 不会在其子问题中被戳破 若果写成dp[i][r - 1]的话 那么r - 1就永远不会被戳破了. dp[r][j]同理
3. 找到base cases(我现在感觉这步非常困难… 需要慢慢分析)
    base case就是只有一个气球能戳的情况 也就是i = j - 2时
    其实base case 还需要考虑i = j, i = j + 1, 这两种情况下都是没有气球可戳的

    对这题来说 其实所有base case都能在循环里直接实现, 但是我把只有一个气球能充的base case单独拿了出来 其他的通过循环直接限制了

```
class Solution {
    public int maxCoins(int[] nums) {
        int len1 = nums.length;

        /** 创建新的数组 为其加上边界值 这两个值是不会被戳的 */
        int[] init = new int[len1 + 2];
        init[0] = 1;
        init[len1 + 1] = 1;
        System.arraycopy(nums, 0, init, 1, len1);

        int len2 = len1 + 2;
        int[][] dp = new int[len2][len2];

        /** base cases */
        for (int i = 0; i <= len2 - 3; i ++) {
        	dp[i][i + 2] = init[i] * init[i + 1] * init[i + 2]; //只有一个气球可以戳
        }
        
        /** 因为默认值就是0 所以没必要写 其实循环里也用不到这两种情况 因为r的循环条件上已经限制了 */
//        for (int i = 0; i <= len2 - 2; i ++) {
//        	dp[i][i + 1] = 0; // 没得戳
//        }	
//        
//        for (int i = 0; i <= len2 - 1; i ++) {
//        	dp[i][i] = 0; // 左右边界重合 
//        }
        
        /** dp 最终要求[0, len - 1] */
        /** 边界不会被戳 即j和i都不会被戳 所以从3开始 这样可以戳1或2 
         *  之所以不从2开始是因为 若从2开始 则只可以戳1 和base cases重合了 */
        for (int j = 3; j <= len2 - 1; j ++) {
            for (int i = j - 3; i >= 0; i --) {
                for (int r = i + 1; r < j; r ++) {
                	// 注意i, j是边界值 不会被戳 所以子问题其实是求戳i + 1 到j - 1个气球能得到的coins
                	// 如果我们最后戳第r个气球 那么我们要确定(i + 1, r - 1)及(r + 1,j - 1)这两个个子问题的coins是最大的
                	// 但是 我们需要给这两个子问题加上边界值 也就是(i, r)和(r, j)的coins是最大的
                    dp[i][j] = Math.max(dp[i][j], init[i] * init[r] * init[j] + dp[i][r] + dp[r][j]); 
                }
            }
        }
        return dp[0][len2 - 1];
    }
    
    public static void main(String[] args) {
    	Solution s  = new Solution();
    	int[] nums = new int[] {3, 1, 5, 8};
    	int res = s.maxCoins(nums);
    	System.out.print(res);
    }
}