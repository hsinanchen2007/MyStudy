### 解题思路
1. 我们首先只考虑 费用最低，那么每个人都能在A、B中选择一个费用低的，然后累加起来
2. 接下来我们考虑 A、B两城市去的人数相同 我们在步骤1中分别记录飞往A地和B地的人数
3. 假如飞往A地的人数大于B地，我们就要把某些飞往A地的票改为飞往B地的，改的过程我们就选择代价最小的即可，也就是说，改票的过程肯定是票价增高的过程，我们用最小堆保存每个人Math.max(costs[i][0],costs[i][1]) - Math.min(costs[i][0],costs[i][1]),每次从A地的堆中选择一个加到总费用中。

### 代码

```java
class Solution {
    public int twoCitySchedCost(int[][] costs) {
        int res = 0;
        //不考虑数量的情况下
        PriorityQueue<Integer> leftmin = new PriorityQueue<>((a,b)->a-b);
        PriorityQueue<Integer> rightmin = new PriorityQueue<>((a,b)->a-b);
        int index = 0;
        int left = 0;
        int right = 0;
        for (int[] cost : costs) {
            if (cost[0] < cost[1]){
                res += cost[0];
                leftmin.add(cost[1] - cost[0]);
                left++;
            }
            else {
                res+= cost[1];
                rightmin.add(cost[0] - cost[1]);
                right++;
            }
        }
        while (left != right){
            if (left > right){
                res += leftmin.poll();
                left--;
                right++;
            }
            else {
                res += rightmin.poll();
                left++;
                right--;
            }
        }
        return res;
    }
}
```