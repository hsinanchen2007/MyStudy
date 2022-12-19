### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int coinChange(int[] coins, int amount) {
        //保留对应金额所需最少的硬币个数
        int [] left = new int[amount + 1];
        left[0] = 0;
        for(int i = 1; i < left.length; i++){
            //每一轮cost暂定是最大值
            int cost = Integer.MAX_VALUE;
            //动态规划思想
            //遍历硬币的面额，找的对应剩下的钱已经求得的最小硬币数+1就可以
            for(int j = 0; j < coins.length; j++){
                if(i - coins[j] >= 0){
                    //如果amout-coins[j]没有零钱可以兑换出，则该方案不成立。
                    if(left[i-coins[j]]!= Integer.MAX_VALUE){
                        cost = Math.min(cost, left[i-coins[j]]+1);
                    }
                    
                }
            }
            //保存最小硬币数
            left[i] = cost;
        }
        return left[amount] == Integer.MAX_VALUE ? -1 : left[amount];
    }
}
```