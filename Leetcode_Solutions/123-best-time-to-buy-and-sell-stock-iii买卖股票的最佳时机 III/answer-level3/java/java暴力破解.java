### 解题思路
此处撰写解题思路
暴力拆解，空间时间复杂度都很高，勉强过了。解题思路：将数组分为前后两部分，分割方式数量prices.length。然后求得第一次交易的最大利润和第二次交易的最大利润并求和，随着分割方式的不同，最大利润的结果也在不断更新。
### 代码

```java
class Solution {
    public int maxProfit(int[] prices) {
        if(prices.length<2) return 0;
        int minFirst = prices[0];
        int maxFirst = prices[0];
        int firstSum = 0;
        int mid = 0;
        int secondSum = 0;
        int sum = 0;
        for(;mid<prices.length;mid++){
            int minSecond = prices[mid];
            int maxSecond = prices[mid];
            for(int i=0;i<prices.length;i++){
                if(i<=mid){
                    if(prices[i]<minFirst){
                        minFirst = prices[i];
                        maxFirst = prices[i];
                    }else if(prices[i]>maxFirst){
                        maxFirst = prices[i];
                        firstSum = maxFirst-minFirst>firstSum?maxFirst-minFirst:firstSum;
                    }
                }else{
                    if(prices[i]<minSecond){
                        minSecond = prices[i];
                        maxSecond = prices[i];
                    }else if(prices[i]>maxSecond){
                        maxSecond = prices[i];
                        secondSum = maxSecond - minSecond>secondSum?maxSecond - minSecond:secondSum;
                    }
                }
            }
            minFirst = prices[0];
            maxFirst = prices[0];
            sum = sum>secondSum+firstSum?sum:secondSum+firstSum;
            firstSum=0;
            secondSum=0;
        }
        return sum;
    }
}
```