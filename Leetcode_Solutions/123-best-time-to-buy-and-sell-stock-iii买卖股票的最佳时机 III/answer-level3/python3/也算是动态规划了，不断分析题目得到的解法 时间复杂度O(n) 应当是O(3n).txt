### 解题思路
买卖股票的最佳时机3 
最多执行两次交易

把数列划分成若干非严格单调递增数列区间
1 5 3 2 4 7
1 5|3 3 |2 4 7
允许同一天买入卖出 等价于当天不操作的结果 所以规定不允许同一天买进卖出

然后将单元素区间扩充成两个 避免出现递减区间 避免出现只有一次买卖 即便原始只有一次买卖 我将区间扩充 等价于第二次买卖获利0 便于讨论
于是只剩下非严格递增区间  而最大利润的买卖方式 在此情况下依然适用（繁琐细节不证明）
数列扩充后 如果在单元素扩充区间先卖出再买进 利润等价 


所有的交易 必定是这些区间的首尾的买入卖出

首先 如果两次买入在同一个递增区间 就会亏掉第二次买入和第一次卖出之间的差值。除非允许同一天交易多次 但是浪费机会也不会增加利润
所以两次买入应当在不同区间
同理 如果两次卖出在同一个递增区间 也会亏掉差值 最多维持利润不变 白白浪费机会 

两次交易的买入必定是某两个区间的首
两次交易的卖出必定是某两个区间的尾

反证法:
    如果某次交易的买入不是某个区间的首 则让买入变为这个区间的首 最少也可以维持利润不变 严格递增则必定利润增加
    如果某次交易的卖出不是某个区间的尾 则让卖出变成这个尾 最少也可以维持利润不变 严格递增必定利润增加

所以问题转化为 
寻找两个买入和两个卖出
买入是两个区间头
卖出是两个区间尾
要求前一个卖出后 后一个才可以买入
寻找这些组合中结果最大的情况
[]
[]
[]
[]
min1 max1 min2 max2 
如果min1 min2 max1 max2 是全局首尾的最小两值和最大两值 那么必然使得max1+max2-min1-min2最大
[1,2,4,2,5,7,2,4,9,0]
7+9-1-2
问题是 如果max1 min2 交错了怎么办
即 min1 min2 max1 max2
min1 min2 max1' min3 max2 这就失去了依据 
所以到头来还得遍历 穷举 
试一试合并

假设p1 p2 q1 q2是某个可能的解
p1 q1是头 p2 q2是尾
如果p1前区间的头小于等于p1 必然可以合并
如果p2后区间的尾部大于等于p2 必然也可以合并

所以是否应该这样
将任务拆解 
最终的数列被分成两部分
左边若干区间 右边若干区间
左边区间贡献出一个最大值组合 用一次性买入股票的方法 右边区间贡献一个最大值 也用一次性买股票的方法
实现时 遍历两遍 做一次记录

而左右两边贡献的最大值 就等价于动态规划实现的结果 因为不要求两个区间紧密相连 所以下一个区间如果产生的值不大 则应当保留前大值利润
### 代码

```python3
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if len(prices)<=1:
            return 0
        in_value = prices[0]
        one_buf = []
        two_buf = []
        for i in range(1,len(prices),1):
            if prices[i]>=prices[i-1]:
                pass
            else:
                temp = prices[i-1]-in_value
                if len(one_buf)>=1:
                    if temp>one_buf[-1]:
                        one_buf.append(temp)
                    else:
                        one_buf.append(one_buf[-1])
                else:
                    one_buf.append(temp)
                if prices[i]<in_value:
                    in_value = prices[i]
            if i==(len(prices)-1):
                one_buf.append(prices[i]-in_value) 
        max_profit = one_buf.pop(-1)
        out_value = prices[-1]
        for i in range(len(prices)-2,-1,-1):
            if prices[i]<=prices[i+1]:
                pass
            else:
                temp = out_value-prices[i+1]
                if len(two_buf)>=1:
                    if temp>two_buf[0]:
                        two_buf.insert(0,temp)
                    else:
                        two_buf.insert(0,two_buf[0])
                else:
                    two_buf.insert(0,temp)
                if prices[i]>out_value:
                    out_value = prices[i]
        for i in range(len(one_buf)):
            temp = one_buf[i]+two_buf[i]
            if temp>max_profit:
                max_profit=temp
        return max_profit
```