### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/abbb79bc0d067e2a534b2cacd7eabd48948975076e8f7b7006ca5029a10c97b4-image.png)
要想跳到第n个台阶上，首先你的位置要处于cost[n-1]或者cost[n-2];
本题的特点是从第0，1层开始往上跳，所以4个数以下时可以直接求出。
### 代码

```java
class Solution {
    public int minCostClimbingStairs(int[] cost) {
        int n = cost.length;
        int[] DP = new int[n+1];
        if(n == 1)
            return cost[0];
        if(n == 2)
            return Math.min(cost[0],cost[1]);
        if(n == 3)
            return Math.min(cost[1],cost[0]+cost[2]);
        DP[1] = cost[0];
        DP[2] = Math.min(cost[0],cost[1]);
        DP[3] = Math.min(cost[1],cost[0]+cost[2]);
        for(int i = 4 ; i <= n ; i ++){
            DP[i] = Math.min(DP[i-2]+cost[i-2],cost[i-1]+DP[i-1]);
        }
        return DP[n];
    }
}
```