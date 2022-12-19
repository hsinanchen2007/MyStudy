### 解题思路
![QQ截图20200313161556.png](https://pic.leetcode-cn.com/47a8fa20fe5e60eacc64112780cdad5836bea31cf7ec6a4bea69dd4579e3cb72-QQ%E6%88%AA%E5%9B%BE20200313161556.png)

之所以又开辟了一个数组p取代prices使用是为了下标统一，都是从1开始到第n天结束，方便阅读，p[1]就是第1天的价格

m[i]：第i天所能获得的最大收益
out_day:到第i天为止，最近一笔交易的抛出日
new_tx:从out_day到第i天，能否产生新的交易，能的话记录其收益的最大值
3个可能的状态
动态规划方程：
m[i]=max{
m[i-1],//第i天什么也不做，如[7,1,5,3]的第4天，此时最近一笔交易是5-1
m[i-1]+new_tx,//从上一笔交易完成到第i天还可以做新的交易，此时就是找最大的new_tx
p[i]-min(p[1]...p[i-1])//到第i天为止只做了一笔交易，就是第i天抛出
}

因为我的dp表是一维的，时间复杂度是O(n^2),人家的dp表是二维的，所以时间复杂度是O(n),这叫什么？这叫降维打击！

这波啊，这波是肉蛋葱鸡
### 代码

```java
class Solution {
    public int maxProfit(int[] prices) {
        if(prices.length<=1){
            return 0;
        }
        int [] p=new int[prices.length+1];
        for(int i=1;i<p.length;i++){
            p[i]=prices[i-1];//下标从1开始使用，王晓东版算法设计的编码风格
        }
        int [] m=new int[p.length];
        m[1]=0;//第1天是无利可图的
        int min_p=p[1];//前i-1天的最小价格
        int out_day=1;//上一笔交易的抛出日,默认第1天
        for(int i=2;i<p.length;i++){//从第2天开始填表
            if(p[i-1]<min_p)  min_p=p[i-1];

            int new_tx=0;//从out_day到第i天，能否产生一笔新的交易，默认不能
            for(int j=out_day;j<i;j++){
                if(p[i]-p[j]>new_tx) new_tx=p[i]-p[j];
            }
            if(new_tx==0){//无新交易可进行
                if(p[i]-min_p>m[i-1]){
                    out_day=i;
                    m[i]=p[i]-min_p;
                }else{
                    m[i]=m[i-1];
                }
            }
            else {//new_tx>0，有新交易可进行
                if(new_tx+m[i-1]>p[i]-min_p){
                    out_day=i;
                    m[i]=new_tx+m[i-1];
                }else{
                    out_day=i;
                    m[i]=p[i]-min_p;
                }

            }

        }
        return m[prices.length];

    }
}
```