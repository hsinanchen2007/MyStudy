### 代码

```java
class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        int sum = 0;
        int srart =-1;
        for(int i =0; i < gas.length; ++i) {
            int num = gas[i] - cost[i];
            sum += num;
        }
        if (sum < 0) {
            return -1;
        }
        // 来到这步，一定能到达，要找出发点（一定存在，分步试），那么假设从第0个加油站出发
        int target=0; //出发点
        int distance = 0;
       
        // 遍历寻找出发点
        for(int i =0; i < gas.length; ++i) {
            distance += gas[i] - cost[i];
            // 排除，从出发点（target）到达不了第i个加油站
            if (distance < 0) {
                distance = 0;
                // 更换出发点，反正一定会存在
                // 该种情况下，如果target不是出发点，那么在target->i之间不会存在出发点
                // 因为target对应的值是正数（否则一开始就不会成为出发点）
                // 所以[target, i]的值累加和小于0，那么(target, i]一定小于0，那么出发点一定不在区间内
                // 大胆将出发点更新i之后的数
                target = i + 1;
            }
        }
        return target;
    }
}
```