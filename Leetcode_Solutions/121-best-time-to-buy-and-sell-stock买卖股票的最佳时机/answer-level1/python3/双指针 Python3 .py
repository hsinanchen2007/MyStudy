### 解题思路
此处撰写解题思路
定义两个指针，一个开头 一个在【1】号位，开始遍历，如果 i的数字 大于 j的数字 则证明可以在j出以更低的价格买入股票
反之如果i处小于j处，则证明可以出售盈利，随后与先前的利润比较，取最大值。
### 代码

```python3
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        i,j,max_money=0,1,0
        while j<len(prices):#因为j一直在i前面 所以只用保证j不超指针范围
            if prices[i] > prices[j]:
                i=j
                j+=1
            else:
                max_money = max(max_money,prices[j]-prices[i])
                j+=1
        return max_money
```