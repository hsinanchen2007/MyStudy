# 157 - 464 我能赢吗

## 题目

在 "100 game" 这个游戏中，两名玩家轮流选择从 1 到 10 的任意整数，累计整数和，先使得累计整数和达到 100 的玩家，即为胜者。

如果我们将游戏规则改为 “玩家不能重复使用整数” 呢？

例如，两个玩家可以轮流从公共整数池中抽取从 1 到 15 的整数（不放回），直到累计整数和 >= 100。

给定一个整数 maxChoosableInteger （整数池中可选择的最大数）和另一个整数 desiredTotal（累计和），判断先出手的玩家是否能稳赢（假设两位玩家游戏时都表现最佳）？

你可以假设 maxChoosableInteger 不会大于 20， desiredTotal 不会大于 300。

示例：

> 输入：
> maxChoosableInteger = 10
> desiredTotal = 11
>
> 输出：
> false
>
> 解释：
> 无论第一个玩家选择哪个整数，他都会失败。
> 第一个玩家可以选择从 1 到 10 的整数。
> 如果第一个玩家选择 1，那么第二个玩家只能选择从 2 到 10 的整数。
> 第二个玩家可以通过选择整数 10（那么累积和为 11 >= desiredTotal），从而取得胜利.
> 同样地，第一个玩家选择任意其他整数，第二个玩家都会赢。

## 解答

又是一道看不懂的题目。。。

> https://leetcode.com/problems/can-i-win/discuss/159797/Python-83-simple-READABLE-code-with-good-comments
>
> https://leetcode.com/problems/can-i-win/discuss/95320/Clean-C%2B%2B-beat-98.4-DFS-with-early-termination-check-(detailed-explanation)

方法就是，把所有可能都试一遍，看看哪种能赢。不能赢的话就把这些数字要输，记录下来。因此要存一下遍历的情形。这里用的是hash表。

边界条件：

1. 如果所有可能的数加起来都不够目标数，那么没有赢家
2. 加起来如果恰好是目标数，那么奇数轮出招的人赢
3. 如果最大可选数大于目标数，那么直接赢

用一个函数判断能不能赢。参数：

- 现有的选择
- 剩余目标数字

如果现有选择的最大值，比目标还大，那么就直接赢了

如果在遍历中曾经见过某个数字的情况，那么就直接返回。

然后开始遍历。

就见五种可能性都来一遍，直到能赢，就记录下来。不然就输。

```python
class Solution:
    def canIWin(self, maxChoosableInteger: int, desiredTotal: int) -> bool:
        msum = maxChoosableInteger*(maxChoosableInteger+1)//2
        if msum < desiredTotal:
            return False
        elif msum == desiredTotal:
            return maxChoosableInteger % 2 == 1
        elif maxChoosableInteger > desiredTotal:
            return True

        seen = {}

        def can_win(choices, remainder):
            if choices[-1] >= remainder:
                return True

            seen_key = tuple(choices)
            if seen_key in seen:
                return seen[seen_key]

            for index in range(len(choices)):
                if not can_win(choices[:index] + choices[index + 1:], remainder - choices[index]):
                    seen[seen_key] = True
                    return True

            seen[seen_key] = False
            return False
        return can_win(list(range(1, maxChoosableInteger+1)), desiredTotal)
```

> Runtime: 328 ms, faster than 98.20% of Python3 online submissions for Can I Win.
>
> Memory Usage: 25.3 MB, less than 100.00% of Python3 online submissions for Can I Win.

另一种用位来记录的花哨做法：

> https://leetcode.com/problems/can-i-win/discuss/134533/Python-Simple-and-Readable-with-Explanation-(Beat-93)

- `k&(1<<i)`，返回k的第i位是否是1
- `k|(1<<i)`，k的第i位变成1

```python
class Solution(object):
    def canIWin(self, maxChoosableInteger, desiredTotal):
        max_sum = maxChoosableInteger*(maxChoosableInteger+1)//2

        if max_sum < desiredTotal:
            return False
        elif max_sum == desiredTotal:
            return (maxChoosableInteger % 2 == 1)

        if maxChoosableInteger >= desiredTotal:
            return True

        bit_mask = 1 << maxChoosableInteger
        self.record = {}

        return self.checkWin(maxChoosableInteger, bit_mask, desiredTotal)

    def checkWin(self, max_num, bit_mask, remain_sum):

        if bit_mask in self.record:
            return self.record[bit_mask]

        for i in range(max_num):
            if (1 & (bit_mask >> i)) != 0:
                continue

            n = i+1
            if (n >= remain_sum) or (self.checkWin(max_num, bit_mask | (1 << i), remain_sum-n) is False):
                self.record[bit_mask] = True
                return True

        self.record[bit_mask] = False
        return False
```

> Runtime: 432 ms, faster than 83.01% of Python3 online submissions for Can I Win.
>
> Memory Usage: 17.9 MB, less than 100.00% of Python3 online submissions for Can I Win.