# 163 - 877 石子游戏

## 题目

亚历克斯和李用几堆石子在做游戏。偶数堆石子排成一行，每堆都有正整数颗石子 piles[i] 。

游戏以谁手中的石子最多来决出胜负。石子的总数是奇数，所以没有平局。

亚历克斯和李轮流进行，亚历克斯先开始。 每回合，玩家从行的开始或结束处取走整堆石头。 这种情况一直持续到没有更多的石子堆为止，此时手中石子最多的玩家获胜。

假设亚历克斯和李都发挥出最佳水平，当亚历克斯赢得比赛时返回 true ，当李赢得比赛时返回 false 。

示例：

> 输入：[5,3,4,5]
> 输出：true
> 解释：
> 亚历克斯先开始，只能拿前 5 颗或后 5 颗石子 。
> 假设他取了前 5 颗，这一行就变成了 [3,4,5] 。
> 如果李拿走前 3 颗，那么剩下的是 [4,5]，亚历克斯拿走后 5 颗赢得 10 分。
> 如果李拿走后 5 颗，那么剩下的是 [3,4]，亚历克斯拿走后 4 颗赢得 9 分。
> 这表明，取前 5 颗石子对亚历克斯来说是一个胜利的举动，所以我们返回 true 。


提示：

1. 2 <= piles.length <= 500
2. piles.length 是偶数。
3. 1 <= piles[i] <= 500
4. sum(piles) 是奇数。

## 解答

### 动态规划

用两个变量存双方的战果，用两个指针指取后的结果，不然每次都换新数组有点浪费资源。

然后用一个dp数组存每次取后的结果，奇数存alex结果，偶数存lee结果。

```python
class Solution:
    def stoneGame(self, piles: List[int]) -> bool:
        left = 0
        right = len(piles)-1
        dp = [0]*len(piles)
        if(piles[left] > piles[right]):
            dp[0] = piles[left]
            left += 1
        else:
            dp[0] = piles[right]
            right -= 1

        if(piles[left] > piles[right]):
            dp[1] = piles[left]
            left += 1
        else:
            dp[1] = piles[right]
            right -= 1

        i = 2
        while(left < right):
            if(piles[left] > piles[right]):
                dp[i] = dp[i-2] + piles[left]
                left += 1
            else:
                dp[i] = dp[i-2] + piles[right]
                right -= 1
            i += 1
        return dp[-1] < dp[-2]
```

> Runtime: 32 ms, faster than 96.05% of Python3 online submissions for Stone Game.
>
> Memory Usage: 12.6 MB, less than 100.00% of Python3 online submissions for Stone Game.

就，非常挫，同一段代码用了三次

```python
class Solution:
    def stoneGame(self, piles: List[int]) -> bool:
        dp = piles[:]
        for j in range(1, len(piles)):
            for i in range(j-1, -1, -1):
                dp[i] = max(piles[i]-dp[i+1], piles[j]-dp[i])
        return dp[0] > 0
```

> Runtime: 240 ms, faster than 50.53% of Python3 online submissions for Stone Game.
>
> Memory Usage: 12.8 MB, less than 100.00% of Python3 online submissions for Stone Game.

### 数学

简言之，`return true`就完事了。。

来看看各语言的效率对比：

![image-20191206100117673](https://pic.leetcode-cn.com/8cccb784613b112d0eaf6662d082a7e1bc0177c4e3c72fda86b9e5cc6c3227a9.jpg)

我说go最牛批没问题吧

