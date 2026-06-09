自己一上来能想到的也只有暴力解法，然后看了官方题解还不是很理解，又看了看诸位大神的思路，明白了一些。现在分享下自己的心得吧。

我主要是想比较下动态规划和暴力法，为什么就能少了很多不必要的遍历呢。关键就是在遍历到i时，我们不用再一个个去求i之前的各项差值然后比较，而是事先记录好i之前的最小值，那么所求的差值一定是当前最大的。

暴力法
```
int[]prices = [7,1,5,3,6,4];
int maxprofit = 0;
(这里i是卖出时间)
for(int i=1;i<prices.length;i++){

  for(int j=0;j<i;j++){
   
   int profit = price[i]-prices[j];
    if(profit>0&&profit>maxprofit){
          maxprofit = profit;
        }
 }
}
```



动态规划
```
int[]prices = [7,1,5,3,6,4];
int maxprofit = 0;
int min = prices[0];
for(int i=1;i<prices.length;i++){

 min = (min<prices[i-1])?min:prices[i-1];

 //注意和暴力法中循环各项然后分别求利润做对比，这里只需要减掉之前记录的最小值即可。
 int profit = prices[i]-min;
 
  if(profit>0&&profit>maxprofit){
          maxprofit = profit;
        }
}
```

# 注意，我这里直接取得min = prices[0],没有去考虑空数组的情况，只是为了便于比较。真正解题的时候需要再加上个判断。




