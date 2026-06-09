### 解题思路
我是小菜鸡，这个提交和击败都不能上台面：这题无非就是计算一个数组中两个元素之间的最大差值，但有一个条件就是只能后面减去前面，因为不能倒序购入股票，我们双遍历该数组，不停地更新MAX的值，遍历完毕MAX存储的一定是最大值。如果MAX=0，意味着数组中差值要么有0，要么都小于0，则返回0，否则返回该MAX即可。代码挺简洁，可以参考下。

### 代码

```java
class Solution {
    public int maxProfit(int[] prices) {
        int MAX = 0;
        for(int i = 0;i<prices.length-1;i++) {
            for(int j = i+1;j<prices.length;j++) {
                if(MAX<=prices[j]-prices[i]) {
                    MAX = prices[j]-prices[i];
                }
            }
        }
        if(MAX==0) {
            return 0;
        }
        return MAX;
    }
}
```