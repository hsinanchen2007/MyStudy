### 解题思路
感谢题解区的小伙伴，还有某同学，让我在危机四伏的股市中取得微薄的利润
只要求出每个上涨日，在上涨日交易，否则就不交易，便能解出
遍历一次price，找到上涨日，存到list里（我是怕数组不好控制大小），再遍历list，将每个上涨日的收益全部相加就可以了

### 代码

```java
class Solution {
    public int maxProfit(int[] prices) {
        int profit=0;
        ArrayList<Integer> list = new ArrayList<>();
        for(int i=0;i<prices.length-1;i++){
            if(prices[i+1]>prices[i]){
                list.add(i);
            }
        }
        for(int i=0;i<list.size();i++){
            int j=list.get(i);
            profit=profit+prices[j+1]-prices[j];
        }
        return profit;
    }
}
```