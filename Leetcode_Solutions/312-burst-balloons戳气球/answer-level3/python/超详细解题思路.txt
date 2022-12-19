

抛开分治法、动态规划这些包袱，我们先分析一下戳气球问题。

很容易发现一种解法：假设气球的编号为1,2, ....., n。我们在第一次戳气球的时候选择编号为k1（k1 >=1 and k1 <= n）的气球戳破，第二次选择 k2(k1 >=1 and k1 <= n and k2 ≠ k1)，.....以此类推。这种解法可以用其他贴子里提到的回溯法实现，这里略过不谈。

分析上述解法的时间复杂度：第一次戳气球的时候有n种选择，第二次的时候有n - 1种选择....，第n次的时候有1中选择。所以，该解法的时间复杂度为 O(！n)。

这样的时间复杂度，显然是万万不能忍的（你能忍面试官也不能忍）。于是考虑使用分治法进行优化。[@niu-you-rou](/u/niu-you-rou/)的[回答](https://leetcode-cn.com/problems/burst-balloons/solution/chao-xiang-xi-hui-su-dao-fen-zhi-dao-dp-by-niu-you/)里可以直观的看出分治法怎样具体优化的：


```
8的阶乘是40320。我们如果将问题分解，比如对半分则我们将得到两个问题规模为4的子问题，时间复杂度为4的阶乘加4的阶乘等于48。

在将规模为8的原问题分解为两个子问题时，我们将会有6种分法，为了覆盖解空间我们需要将所有子问题的分解方式都尝试一次，则尝试所有分法的计算次数为∑( !k +!(n-k)),其中0<k<n。
以问题规模为8时为例，将问题分为两个子问题的计算次数将是1804，与原问题计算40320次时相比，性能得到了极大的提升。
```

好，现在是时候用分治法给原解法整容美形了。假设气球的编号为1,2, ....., n。我们在第一次戳气球的时候选择编号为k1（k1 >=1 and k1 <= n）的气球戳破；此时原问题被划分为 [1, k1)和 (k1, n]这两个子问题。但此时我们发现，改变在(k1, n]这个子问题中戳破了 k1 + 1编号的气球的顺序，则[1, k1) 这个子问题的答案也会随之变动。即[1, k1) 这个子问题的答案和(k1, n]这个子问题的答案是互相依赖的。在子问题相互依赖的前提下，状态转移方程的表示必复杂、低效、难以求解。分治法优化的进程陷入了停滞。

为什么会这样？是静香不够骚，还是分治法眼光高？屏幕前的你不知是否有同样的困惑。其实，**分治法本质上只是一个工具，只能解决特定情境下的问题。当问题难以得到解决的时候，我们除了翻阅工具使用指南，还应该思考问题的情境是否需要重新定义**。就好像发现女友怀孕了，我们除了仔细审视避孕套的正确使用姿势之外，还应该重新思考孩子他爸到底是谁。

抛开分治法，重新思考气球问题。不难发现一种新的解法：假设气球的编号为1,2, ....., n。我们选择编号为k1（k1 >=1 and k1 <= n）的气球作为最后一个被戳破的气球，第二次选择 k2(k1 >=1 and k1 <= n and k2 ≠ k1)......

在这个新解法的基础上使用分治法，子问题的解显然不会依赖于其他的子问题。

假设气球的编号范围为 [i, j]，我们选择编号为k1的气球最后戳爆。此时，父问题被k1切分成左右两个子问题。分析右边的子问题，在编号范围[k1, j]的气球中，选择编号为k2的气球最后戳爆。同时，我们还发现k1作为父问题选择最后戳爆的气球，在子问题中显然不能处理，否则k1就不可能是i到j中最后戳爆的气球；j同理也不能戳爆。据此，可以得出结论：作为边界的气球不做处理，剩余的气球都可以选做最后戳爆的气球。（初始条件下，边界不是由父问题里最后戳爆的气球构成。但在前后增加值为1的两个气球构成新的边界即可解决。）我们尝试分别把编号为 i + 1 ~ j - 1的气球选为最后戳爆的气球，然后选择子问题之和 + nums[i][j][k]最大的为问题的解。

于是有状态转移方程：  def( i, j ) = max { def( i , k ) + def( k , j )+nums[ i ][ j ][ k ] } | i<k<j 

回归条件： def( i , i+1 ) = 0 。



想清楚思路，代码自然一气呵成：

```
class Solution:
    def maxCoins(self, nums: List[int]):


        if not nums:
            return 0


        def getMaxCoins(nums, i, j):
            if i == j - 1:
                return 0
           
            temp = 0

            for k in range(i + 1, j):
                left = getMaxCoins(nums, i, k)
                right = getMaxCoins(nums, k, j)

                temp = max(temp, left + right + nums[i] * nums[k] * nums[j])


            return temp


        nums = [1, *nums, 1]

        return getMaxCoins(nums, 0, len(nums) - 1)
```

上面的代码发现还是accept不了。细心观察，发现可以通过动态规划进一步优化，代码如下：


```
class Solution:
    def maxCoins(self, nums: List[int]):


        if not nums:
            return 0


        def getMaxCoins(nums, i, j, memo):
            if i == j - 1:
                return 0
            if memo[i][j] > 0:
                return memo[i][j]


            temp = 0


            for k in range(i + 1, j):
                left = getMaxCoins(nums, i, k, memo)
                right = getMaxCoins(nums, k, j, memo)


                temp = max(temp, left + right + nums[i] * nums[k] * nums[j])


            memo[i][j] = temp


            return temp


        nums = [1, *nums, 1]
        memo = [[0 for i in nums] for n in nums]


        return getMaxCoins(nums, 0, len(nums) - 1, memo)
```

推荐巩固训练的题目：[DI 序列的有效排列](https://leetcode-cn.com/problems/valid-permutations-for-di-sequence/)
