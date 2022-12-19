执行结果：
通过
显示详情
执行用时 :
1 ms
, 在所有 Java 提交中击败了
99.95%
的用户
内存消耗 :
37.7 MB
, 在所有 Java 提交中击败了
50.14%
的用户
```
class Solution {
    public int maxProfit(int[] prices) {
        int len = prices.length;
        if(len<2)return 0;
        int sum=0;
        int max=prices[0];
        int min=max;
        for(int i=1; i<len; i++){
            int ii = prices[i];
            if(ii>=prices[i-1]){
                max=ii;
            }else{
                sum+=(max-min);
                max=min=ii;
            }
        }
        sum+=(max-min);
        
        return sum;
    }
}
```
