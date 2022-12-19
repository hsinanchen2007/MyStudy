### 解题思路
基本思想是：随着遍历首先会确定一个数组最小值和暂时的最大利润值。
这个时候我们思考，假如后面的数组值比当前最小值大，则后面可以产生的最大利润值一定不如把这个数组值换成当前最小值得到的利润大；
假如后面的数组值比当前最小值小，则后面有可能产生更大的利润值，所以要暂时记录下当前的最大利润值以备后面做比较。
遍历一次数组即可，时间复杂度O(n),空间复杂度没有用到新的数据结构所以是O(1)。

### 代码

```java
class Solution {
    public int maxProfit(int[] prices) {
        int tmpprofit=0;
        int tmpminvalue=Integer.MAX_VALUE;
        for(int i=0;i<prices.length;i++){
            if(prices[i]<tmpminvalue){
                tmpminvalue=prices[i];
            }else{
                if(prices[i]-tmpminvalue>tmpprofit){
                    tmpprofit=prices[i]-tmpminvalue;
                }
            }
        }
        return tmpprofit;
    }
}
```