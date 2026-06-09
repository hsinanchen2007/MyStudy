### 解题思路
此处撰写解题思路
把当前列表从第一个开始遍历，在for循环内部再嵌套一个for循环，遍历的起始为母循环的当前节点，计算所有当前节点之后的所有数据，取差最大的，保存为最大利润
### 代码

```java
class Solution {
    public int maxProfit(int[] prices) {
        int maxProfit = 0;
        for(int i = 0;i<prices.length;i++){
            int tempPrice  = prices[i];
            for(int j = i;j<prices.length;j++){
                int tempJ  = prices[j];
                if(tempJ-tempPrice>maxProfit){
                    maxProfit = tempJ-tempPrice;
                }
            }
        }
        return maxProfit;
    }
}
```。