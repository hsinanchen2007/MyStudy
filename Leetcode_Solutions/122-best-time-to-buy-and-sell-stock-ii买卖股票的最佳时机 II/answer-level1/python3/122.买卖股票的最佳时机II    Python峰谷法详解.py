

模仿121.买卖股票的最佳时机I的解题方法，在原基础上添加股票买卖状态，实现多次买卖求得最大总利润。

**思路：**
1.从前往后遍历，计算最大利润(同121.一次买卖)
2.将每轮最大利润与上一轮比较：
  若不变则说明上一轮应该卖出
  若变化(大)则继续向后遍历寻找更大利润
3.当最后一天时，股票仍未卖出，则卖出或保留，即总利润+=当前最大利润(>=0)

**参考代码：**
```python []
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        minprice=float('inf')#初始化历史最低价
        maxprofit=0#初始化当前最大利润
        profit=0#总利润
        sell=0#初始状态：卖出(0)未卖出(1)
        for price in prices:#从前往后遍历每天的股价
            if maxprofit==max(maxprofit,price-minprice):#若最大利润没变化
                profit+=max(maxprofit,price-minprice)#操作卖出，并累计至总利润
                sell=1#标记卖出
                minprice=price#更新历史最低价为当前股价
                maxprofit=0#初始化当前最大利润
            else:#若最大利润发生变化（大）
                maxprofit=max(maxprofit,price-minprice)#不卖出，并更新当前最大利润
                sell=0#标记未卖出
        if sell==0:profit += maxprofit#最后如果处于未卖出状态，总利润再加当前最大利润
        return profit
```
**复杂度分析：**
时间复杂度：O(n)，遍历一次。
空间复杂度：O(1)，使用常数个变量。

**执行用时 :**
60 ms, 在所有 Python3 提交中击败了82.40%的用户
内存消耗 :
14.4 MB, 在所有 Python3 提交中击败了20.43%的用户

