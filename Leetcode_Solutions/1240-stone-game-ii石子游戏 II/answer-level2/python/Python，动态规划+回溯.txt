同[486. 预测赢家](https://leetcode-cn.com/problems/predict-the-winner/)几乎一个套路的博弈问题，这类题都可以用这种动规+回溯的方法求解

```python
class Solution:
    def stoneGameII(self, piles: List[int]) -> int:
        dp = {}
        N = len(piles)
        # 输入当前的M以及当前剩余石子堆的位置，返回先手能获得的最大积分及该情况下后手积分
        def max_get(M, start):
            if (M, start) in dp:
                return dp[M, start]
            count = N-start  # 剩余堆数
            if count <= 2*M:  # 全部拿完
                dp[M, start] = sum(piles[start:]), 0
            else:
                # 记录先手能获得的最大积分及该情况下后手积分，get为本次拿的积分
                max_pre, max_post, get = 0, 0, 0
                for x in range(min(2*M, count)):
                    _M = max(M, x+1)  # 实际拿的堆数为x+1
                    get += piles[start+x]
                    pre, post = max_get(_M, start+x+1)  # 回溯
                    if get+post > max_pre:  # get+post为当前拿到的积分+回溯下的后手积分
                        max_pre, max_post = get+post, pre  # 替换最大值
                dp[M, start] = max_pre, max_post
            return dp[M, start]
        return max_get(1, 0)[0]
```
