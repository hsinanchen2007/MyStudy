```
class Solution(object):
    
    def __init__(self):
        self.max_profile=float('-inf')
        self.prices=None
        self.m=0

    def dfs(self,i,status,profit,ava_count):

        '''
        i: 第i天的股票价格prices[i]
        stauts: 1 买入 2 卖出 3 买入后持平 4 卖出后持平
        profit: 当前利润
        ava_count: 可用交易次数
        1->2 1->3
        2->4
        3->2
        4->1
        '''
        
        if i>self.m-1:
            self.max_profile=max(self.max_profile,profit)
            return 
       #状态1 买入 
        if status==1:
            #可能转化为状态2 卖出
            self.dfs(i+1,2,profit+(0 if i+1>self.m-1 else self.prices[i+1]),ava_count)
            #可能转化为状态3 买入后等待
            self.dfs(i+1,3,profit+0,ava_count)
        #状态2 卖出
        elif status==2:
            #可用次数减量
            ava_count-=1
            #TODO 如过还有可用次数，可转化为等待状态
            if ava_count>0:
                self.dfs(i+1,4,profit+0,ava_count)
            #如果没有可用次数，直接计算出当前利润
            else:
                self.max_profile=max(self.max_profile,profit)
                return 
        #如果当前为状态3 买入后等待
        elif status==3:
            #可以转化为2 卖出
            self.dfs(i+1,2,profit+(0 if i+1>self.m-1 else self.prices[i+1]),ava_count)
            #可以转化为3 买入后等待
            self.dfs(i+1,3,profit+0,ava_count)
        #如果当前状态为4 卖出后等待
        elif status==4:
            #如果还有可用次数
            if ava_count>0:
                #可能转化为状态1 买入
                self.dfs(i+1,1,profit-(0 if i+1>self.m-1 else self.prices[i+1]),ava_count)
            #可能转化为状态4 买入后等待
            self.dfs(i+1,4,profit+0,ava_count)


    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        self.prices=prices
        self.m=len(prices)
        if self.m==0:
            return 0
        if self.m==1:
            return 0
        if self.m==2:
            return prices[1]-prices[0] if prices[1]-prices[0] >0 else 0
        
        #状态 买和不买
        self.dfs(0,1,-prices[0],1)
        self.dfs(0,4,0,1)

        return self.max_profile
        
```
