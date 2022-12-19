### 解题思路
此处撰写解题思路
JAVA实现，思路就是后面比前面打就进行累计，
但是要注意数组是否已经排序，如果已经排序好的数组就直接用最后一个减去第一个即可。
大神有优化的想法请留言。
### 代码

```java
class Solution {
    public int maxProfit(int[] prices) {
        if(prices == null || prices.length < 2 ){
            return 0;
        }
        int len=prices.length;
        if(isSord(prices)){
            return prices[len-1] -prices[0];
        }
        
        int maxSum=0;
        for(int i=0;i<len-1 ; i++){
            
            if(prices[i+1]-prices[i] > 0 ){
                maxSum += (prices[i+1]-prices[i]);
            }
        }
        return maxSum;

    }
    public boolean isSord(int[] prices) {
        boolean flag = true;
        for(int i=0;i<prices.length;i++){
            if(i==prices.length-1){
                break;
            }
            if(prices[i+1]<prices[i]){
                flag = false;
            }
        }
        return flag;
    }
}
```