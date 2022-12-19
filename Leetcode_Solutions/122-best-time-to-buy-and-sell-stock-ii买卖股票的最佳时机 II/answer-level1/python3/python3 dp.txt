### 解题思路
我们可以简单地继续在斜坡上爬升并持续增加从连续交易中获得的利润，而不是在谷之后寻找每个峰值。最后，我们将有效地使用峰值和谷值，但我们不需要跟踪峰值和谷值对应的成本以及最大利润，但我们可以直接继续增加加数组的连续数字之间的差值，如果第二个数字大于第一个数字，我们获得的总和将是最大利润。这种方法将简化解决方案。
这个例子可以更清楚地展现上述情况：

[1, 7, 2, 3, 6, 7, 6, 7]

与此数组对应的图形是：

著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
![](https://pic.leetcode-cn.com/86fc2371bec63d3189bf8e1493b817e1bc5dc9b4f3fbecab3cbbc7ffa11cf299-6eaf01901108809ca5dfeaef75c9417d6b287c841065525083d1e2aac0ea1de4-file_1555699697692.png)

我们可以观察到 A+B+CA+B+C 的和等于差值 DD 所对应的连续峰和谷的高度之差。

![](https://pic.leetcode-cn.com/18929b6fa05b8c64db69655b3232a806c866275b9881611e8316b2c2d6fec484-%E6%88%AA%E5%B1%8F2020-03-09%E4%B8%8B%E5%8D%888.43.32.png)

### 代码

```python []
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        maxprofit = 0
        for i in range(1, len(prices)):
            maxprofit += max(0, prices[i] - prices[i-1])
        return maxprofit
```