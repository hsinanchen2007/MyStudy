### 解题思路
这个问题就是理清两个范围的问题
最小值的范围是越来越大 而最大值的范围越来越小
所以只有可能最小值是更新的 而最大值永远要看下一个值
再维护一个差就行了

### 代码

```java

class Solution {
    public int maxProfit(int[] prices) {
    int diff=0;
    
    if(prices.length==0)
    return 0;
    int min=prices[0];
    for (int i = 1 ; i <prices.length; i++){
           if(prices[i]<min){
               min=prices[i];
           }else{
               if(prices[i]-min>diff)
               diff=prices[i]-min;
    }
    }
    return diff;
    }
}
```