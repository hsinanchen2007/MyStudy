把走势图画出来，很容易发现，其实就是求原来数组里面所有升序子串的起点和终点差值之和。
```
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        ans = 0
        if prices:
            # 记录当前升序子串的起点和终点
            cur_min = cur_max = prices[0]
            for i in range(1, len(prices)):
                # 新的升序子串的起点，结算上一次
                if prices[i] <= prices[i - 1]:
                    if cur_max > cur_min:
                        ans += cur_max - cur_min
                    cur_max = cur_min = prices[i]
                else:
                    cur_max = prices[i]
            # 在结尾结束的最后一个升序子串，也要加起来
            if cur_max > cur_min:
                ans += cur_max - cur_min
        return ans
```
