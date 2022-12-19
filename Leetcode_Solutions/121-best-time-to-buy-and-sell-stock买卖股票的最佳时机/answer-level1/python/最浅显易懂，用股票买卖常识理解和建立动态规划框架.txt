在leetcode中，有6道题与股票买卖相关，需要获得最大利润。本人从实际生活中股票买卖常识来解题，并给出更易理解和更简洁高效的框架解决方案。
我们知道，股票利润公式：利润 =（卖价-买价）*数量
设定数量=1，公式简化为：利润 = 卖价-买价
我们就根据上述人人皆知的公式，进行推导和解题。
一、leetcode 121题
该题给出一个股价数组prices, 数值中的值表示第i天股票价格，只能一次交易，得到最大利润。
最大利润：max(利润)=max(卖价-买价)，就是比较卖价和买价的价差，得到最大的。
对于卖价，第 i 天只有一个，是唯一的，不用选择。
对于买价，第 i 天之前有i-1个买价，只有选择最低的，才能得到最大价差即利润最大。
相应程序（python语言，以下同）如下：
程序形式0
```
def maxProfit_myself(self, prices: List[int]) -> int:
    buy=float('inf')
    profit=0
    for i in range(len(prices)-1):
        buy=min(buy,prices[i])               #股票买价，在第i天买，选择最低的
        profit=max(profit,prices[i+1]-buy)   #股票利润，在第i天后卖，选择利润最大的 
    return profit
```
该程序中，profit表示股票利润，buy表示购买价格，先买后卖，大家一看就明白。
为了程序美观，可以将买卖语句调换一下，形式变了，其解题思路和结果完全一样
程序形式1
```
def maxProfit_myself(self, prices: List[int]) -> int:
    buy=float('inf')
    profit=0
    for i in range(len(prices)):
        profit=max(profit,prices[i]-buy)       #股票利润，在第i天卖出以前买入的，选择最大的
        buy=min(buy,prices[i])                 #股票买价，在第i天买 ，选择最低的
    return profit
```

该程序中，变量名称和含义与程序形式0完全一致，从形式上先执行股票卖出语句，后执行股票买入语句，但程序逻辑上，还是先买后卖，但循环变量i和prices取值更简洁了。
在程序形式0和程序形式1中，profit表示股票利润，buy表示购买价格，可以再进行变换，把profit和buy变成含义一致，就像数学和物理应用题把单位统一，我们知道利润公式，
利润 = 卖价-买价，形式变化为：利润 = 卖价+（-买价）
可以这样理解，利润由两部分构成，一部分是卖价产生的利润，我们称之为卖出利润，一部分是（-买价）产生的利润，（-买价）实际意义是已经付钱购买股票在手，我们称之为持股利润。
这样公式可以写为：利润 = 卖出利润（股票卖价）+ 持股利润 （ - 买价）
对应地，程序进行相应改变：
程序形式2
```

def maxProfit_myself_3(self, prices: List[int]) -> int:
    hold = float('-inf')
    profit = 0
    for i in range(len(prices)):
        profit = max(profit, hold+prices[i])     #利润=持股利润+卖出利润 
        hold = max(hold, -prices[i])             #持股利润，选择最大的
    return profit
```

该程序与程序形式1有个变化，hold = -buy，因此，选择最小就变成选择最大。
该题是只能买卖一次股票，如果多次购买股票，如何适用呢？下面继续探讨。
二、leetcode 123题
该题给出一个股价数组prices, 数值中的值表示第i天股票价格，最多两次交易，获得最大利润。
其思路还是与上题一样，可以分别写出程序形式1和程序形式2的核心语句：
程序形式1
profit1=max(profit1,prices[i]-buy1) #股票利润1，在第i天卖出以前买入的，选择最大的
buy1=min(buy1,prices[i]) #股票买价1，在第i天买 ，选择最低的
profit2=max(profit2,prices[i]-buy2) #股票利润2，在第i天卖出以前买入的，选择最大的
buy2=min(buy2,prices[i]-profit1) #股票买价2，在第i天买，买价-股票利润1
可以看到，在buy2中股票购买价格变成了prices[i]-profit1，为什么呢？
其实很好理解，第一次买股票，花的钱都是你的本钱，第二次买股票，扣除第一次挣的钱，才是你花的本钱。
也可以从下面公式推导出来：
利润=利润1+利润2=利润1+卖价2-买价2=卖价2 -（买价2-利润1）
此时，第二次的股票买价变成了（买价2-利润1）
程序形式2
profit1 = max(profit1, hold1+prices[i]) #利润1=持股利润1+卖出利润1
hold1 = max(hold1, -prices[i]) #持股利润1，选择最大的
profit2 = max(profit2, hold2+prices[i]) #利润2=持股利润2+卖出利润2
hold2 = max(hold2, profit1-prices[i]) #持股利润2，选择最大的
可以看到，在hold2中持股利润变成了profit1-prices[i]，怎么得来的？
第一种方式，可以从hold2 = -buy2得到结论
第二种方式，可以从股票利润公式可以推导：
利润=利润1+利润2=利润1+卖价2-买价2=卖价2+（利润1-买价2）
因此，第二次持股利润 =（利润1-买价2）
程序形式1完整程序
```
def maxProfit_myself_cost(self, prices: List[int]) -> int:
    profit1=profit2=0
    buy1=buy2=float('inf')
    for i in range(len(prices)):
        profit1 = max(profit1, prices[i] - buy1)  # 股票利润1，选择最大的
        buy1 = min(buy1, prices[i])               # 股票买价1，在第i天买 ，选择最低的
        profit2 = max(profit2, prices[i] - buy2)  # 股票利润2，选择最大的
        buy2 = min(buy2, prices[i] - profit1)     # 股票买价2，在第i天买，买价-股票利润1
    return profit2
```

程序形式2完整程序：
```
def maxProfit_myself(self, prices: List[int]) -> int:
    profit1 = profit2 = 0
    hold1 = hold2 = float('-inf')
    for i in range(len(prices)):
        profit1 = max(profit1, hold1 + prices[i])  # 第1次股票利润
        hold1 = max(hold1, -prices[i])             # 第1次持股利润
        profit2 = max(profit2, hold2 + prices[i])  # 第2次股票利润
        hold2 = max(hold2, profit1 - prices[i])    # 第2次持股利润
    return profit2
```

有人会说，对于两次交易，可以列出来，对于更多次交易呢？对于10次8次交易，也需要列出来吗？当然不用，完整程序如下：
程序形式1
```
def maxProfit_myself_cost_iter(self, prices: List[int]) -> int:
    K=2  #交易次数，可以任意指定
    profit=[0 for _ in range(K)]
    buy=[float('inf') for _ in range(K)]
    for i in range(len(prices)):
        for k in range(K):
            if k==0:
                pre_profit=0   #pre_profit购买股票时前期利润
            profit[k]=max(profit[k],prices[i]-buy[k])    #股票利润
            buy[k]=min(buy[k],prices[i]-pre_profit)      #股票购买价格
            pre_profit=profit[k]
    return profit[K-1]
```

程序形式2
```
def maxProfit_myself_iter(self, prices: List[int]) -> int:
    K=2  #交易次数,可以随意指定
    profit=[0 for _ in range(K)]
    hold=[float('-inf') for _ in range(K)]
    for i in range(len(prices)):
        for k in range(K):
            if k==0:
                pre_profit=0   #pre_profit购买股票时前期利润
            profit[k]=max(profit[k],hold[k]+prices[i])     #股票利润
            hold[k]=max(hold[k],pre_profit-prices[i])      #持股利润
            pre_profit=profit[k]
    return profit[K-1]
```

只要前面明白，上述程序不难理解。
注意交易次数k的选择，如果k>len(prices)//2，就相当于无穷大，实际上不需要考虑k，数组从头循环到尾即可，凡是有利润就买入和卖出股票。
三、总结
上面两种程序形式，可以总结为下面两种通用框架：
通用框架1：
profit=max(profit,prices[i]-buy) #股票利润
buy=min(buy,prices[i]-profit) #股票购买价格
通用框架2：
profit=max(profit,hold+prices[i]) #股票利润
hold=max(hold,profit-prices[i]) #持股利润
上面两种通用框架，其实就是动态规划，股票利润是状态，股票买卖改变了利润大小。
该通用框架，可以解决其它股票题目，相比其它动态框架更容易理解，更简洁高效。