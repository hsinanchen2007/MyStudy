## 原始转移方程
考虑第i天不持有dp[i][0]和持有dp[i][1]的转移方程：

dp[i][0]=max(dp[i-1][0],dp[i-1][1]+p[i])
dp[i][1]=max(dp[i-1][1],dp[i-2][0]-p[i])

## 压缩
可以对i这个属性进行压缩，但是计算i需要i-1和i-2的信息，所以至少需要三行记录（类似斐波那契求解）
cur[1]=max(bf1[1],bf2[0]-p[i])
cur[0]=max(bf1[0],bf1[1]+p[i])
初始化：
i=0:cur[0]=0,cur[1]=-p[0],bf1[0]=0,bf1[1]=MIN

实现代码为：
```
public int maxProfit(int[] prices) {
        int n=prices.length;
        if(n==0){
            return 0;
        }
        int[] bf2=new int[2];
        int[] bf1=new int[2];
        bf2[1]=Integer.MIN_VALUE;
        bf1[1]=-prices[0];
        int[] cur=new int[2];
        for(int i=1;i<n;i++){
           cur[1]=Math.max(bf1[1],bf2[0]==Integer.MIN_VALUE?
Integer.MIN_VALUE:bf2[0]-prices[i]);//在前天买入
           cur[0]=Math.max(bf1[0],bf1[1]+prices[i]);//卖出

           copy(bf1,bf2);
           copy(cur,bf1);
        }
        return cur[0];
    }

    
    private void copy(int[] from,int[] to){
        to[0]=from[0];
        to[1]=from[1];
    }
```

## 进一步减少记录的变量
细想一下，其实也不需要三个变量数组来记录，只需要增加两个个记录0的临时变量：cur0和cur1代表当前第i天持有和不持有股票的收益，bf1代表i-1天不持有，bf2代表第i-2天不持有。
cur0=max(cur0,bf2-p[i])
cur1=max(cur1,cur0+p[i])
```
public int maxProfit(int[] prices) {
        int n=prices.length;
        if(n==0){
            return 0;
        }

        int bf1=0;
        int bf2=0;
        int cur0=0;
        int cur1=Integer.MIN_VALUE;//i=-1，持有是不可能的
        for(int i=0;i<n;i++){
           cur1=Math.max(cur1,bf2-prices[i]);
           cur0=Math.max(cur0,cur1+prices[i]);

            bf2=bf1;
            bf1=cur0;
        }
        return cur0;
    }
```


