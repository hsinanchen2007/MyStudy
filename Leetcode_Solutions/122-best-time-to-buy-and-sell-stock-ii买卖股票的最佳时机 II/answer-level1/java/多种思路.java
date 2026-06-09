#### 1. 动态规划
首先对于这个题，我们定义状态为dp[i][j],就是对于第i天，持有或者没有股票的最大的收益，因为交易次数不限，所以这个状态可以省略，由此状态转移方程定义为：
`dp[i][0]=Math.max(dp[i-1][0],dp[i-1][1]+prices[i])`
`dp[i][1]=Math.max(dp[i-1][1],dp[i-1][0]-prices[i])`
```
class Solution {
    public int maxProfit(int[] prices) {
        /*
        状态：  天数，交易次数，是否持有股票
        dp[i][j][0] 表示第i天，最大交易次数为j，没有股票的最大的收益
        dp[i][j][1] 表示第i天，最大交易次数为j，持有股票的最大的收益
        状态转移方程：
        dp[i][j][0]=max(dp[i-1][j][0],dp[i-1][j][1]+prices[i])
        dp[i][j][1]=max(dp[i-1][j][1],dp[i-1][j-1][0]-prices[i])
        这里由于j为无群大，所以这个状态已经没有意义了，就可以不写，最后状态转移方程变为：
        dp[i][0]=max(dp[i-1][0],dp[i-1][1]+prices[i])
        dp[i][1]=max(dp[i-1][1],dp[i-1][0]-prices[i])
        */
        int n=prices.length;
        
        if(n==0||n==1) return 0;
        
        int dp[][]=new int[n][2];
        
        //初始化
        dp[0][0]=0; dp[0][1]=-prices[0];
        
        for(int i=1;i<n;i++){
            dp[i][0]=Math.max(dp[i-1][0],dp[i-1][1]+prices[i]);
            dp[i][1]=Math.max(dp[i-1][1],dp[i-1][0]-prices[i]);
        }
        
        return dp[n-1][0];
    }
}
```
#### 2. 波峰波谷配对
我们来看一个例子
[7,3,4,8,4,6],这里，我们画出它的折线图
![image.png](https://pic.leetcode-cn.com/de39e25ab444109d6889099b7fda27ad24a951d55ab4356f4c3be60ffc65a6ac-image.png)
这里我们标记了两组波峰和波谷，什么意思呢，就是我们首先找到一个波谷，然后找到离这个波谷最近的波峰，找到所有这样的配对，求得差值，累加到结果中就好了
```
class Solution {
    public int maxProfit(int[] prices) {
        int n=prices.length;
        
        if(n==0||n==1) return 0;
        
        int max_pro=0;
        
        int valley=0;
        int peek=0;
        
        int i=0;
        while(i<n-1){
            while(i<n-1&&prices[i]>=prices[i+1]) i++;
            valley=prices[i];
            while(i<n-1&&prices[i]<=prices[i+1]) i++;
            peek=prices[i];
            
            max_pro+=peek-valley;
        }
        
        return max_pro;
    }
}
```

#### 3.第二种思路的另一种写法
从第二种方法所画的折线图可以看出，如果一个股票在连续的n天内价格只增不减，那其实用它第n天的价格减去最初的价格就是这n天的最大的收益，如果在第n+1天股票价格减少了，那n到n+1天的收益肯定是负的，就不能加到结果中了，也就是说，只要有连续增长的区间，就直接用区间结尾减去区间开头的价格就是这个区间的最大的收益，其实这个区间的结尾对应的就是波峰，开头对应的就是波谷，上述就是第二种写法的一个解释，那么这种写法是怎么写的呢，（其实这种写法是和题意不符的，因为它的意思是当前卖了前面买的，然后继续买当前的股票）但是也可以得到正确的解，因为例如一个股票在[1,3]天的价格为1,3,5,这种写法就是3-1+5-3，其实就是第二种写法的5-1，这两者的结果是相同的，由此第二种写法就改变为了只要后一天的股票价格大于前一天的股票价格，就把这个收益加上
```

class Solution {
    public int maxProfit(int[] prices) {
        //直接遍历所有的买入和卖出，只要收益是正数，就加上
        int n=prices.length;
        
        int max_pro=0;
 
        for(int i=0,j=1;j<n;i++,j++){
            int cur=prices[j]-prices[i];
            
            if(cur>0) max_pro+=cur;
        }
        
        return max_pro;
    }
}
```
<br/>
## 画图有些丑，请大家见谅