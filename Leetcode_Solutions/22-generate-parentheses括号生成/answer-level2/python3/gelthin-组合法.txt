### 解题思路
2020.3.20

腾讯2面的面试题，3. 你卖东西，每份5元，现在有 100 个人，50 个人带了 5元整钱，50 个人带来 10元整， 问这100个人有多少排列方式，你能成功找零

卡特兰数，编程之美上讲过此。


采用官方题解 3 的思路： 组合法
设括号对数为 n, 每一个解都必然形如： '(' + left + ')' + right， 其中 left 和right 都是有效的括号序列。
记 left 中的括号对数为 k, 则 k=0, 1, 2, ..., n-1， right 中的对数为 n-k-1。 

递归调用 solution(k), solution(n-k-1), 问题规模也变小了。但这里计算复杂度太高了，就像是递归计算斐波那契数列，复杂度太高。如果能暂存起来，减少不小复杂度。

这个又不同于回溯法，回溯法主要用于排列组会，枚举，避免产生大量的中间状态，只在一个状态变量上修改。回溯法参见 liweiwei 题解 [从全排列问题开始理解“回溯搜索”算法（深度优先遍历 + 状态重置 + 剪枝）](https://leetcode-cn.com/problems/permutations/solution/hui-su-suan-fa-python-dai-ma-java-dai-ma-by-liweiw/)

组合法是一个非常妙的方法，分治递归的典型，此思想值得好好领悟，细细思考！
liweiwei 的解法[回溯算法（深度优先遍历）+ 广度优先遍历 + 动态规划](https://leetcode-cn.com/problems/generate-parentheses/solution/hui-su-suan-fa-by-liweiwei1419/) 给出了从 DP 角度的更加细致的分析，也就是说把每一步的解都存储起来，然后直接调用返回。这个是由递归实现的 DP， 也有由迭代实现的 DP, 迭代实现稍微复杂一点。


> 方法三：闭合数 (from 官方题解) 
> 思路 
>为了枚举某些内容，我们通常希望将其表示为更容易计算的不相交子集的总和。

>考虑有效括号序列 S 的 闭包数：至少存在 index >= 0，使得 S[0], S[1], ..., S[2*index+1]是有效的。 显然，每个括号序列都有一个唯一的闭包号。 我们可以尝试单独列举它们。

>算法
>对于每个闭合数 c，我们知道起始和结束括号必定位于索引 0 和 2*c + 1。然后两者间的 2*c 个元素一定是有效序列，其余元素一定是有效序列。

### 代码

```python3
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        ## 所谓的组合法

        if n == 0:
            return ['']
        # (left)right
        result = []
        for k in range(n-1,-1,-1):   # 为了和实例 n=3 结果对应， left 的长度从大到小
            for left in self.generateParenthesis(k):  
                for right in self.generateParenthesis(n-1-k):
                    ans = '(' + left + ')'+ right
                    result.append(ans)
        return result

```