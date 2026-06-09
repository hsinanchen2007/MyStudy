```
class Solution {
    public int maxProfit(int[] prices) {
        int len=prices.length;
        if(len<=1)return 0;
        int min=prices[0];//记录最小值
        int[] max=new int[len];//记录每一天能赚的最大值
        int maxall=0;//总的最大值
        for(int i=1;i<len;i++){
            if(prices[i]>prices[i-1]){
                max[i]=max[i-1]+prices[i]-prices[i-1];
            }else{
                min=min<prices[i]?min:prices[i];
                max[i]=prices[i]-min;
            }
            maxall=maxall>max[i]?maxall:max[i];
        }
        return maxall;
    }
}
```
上面的看上去比较繁琐，改进后：
```
class Solution {
    public int maxProfit(int[] prices) {
        int min=Integer.MAX_VALUE;//记录最小值
        int max=0;//记录最大值
        for(int i=0;i<prices.length;i++){
            min=min<prices[i]?min:prices[i];
            max=Math.max(max,prices[i]-min);
        }
        return max;
    }
}
```

