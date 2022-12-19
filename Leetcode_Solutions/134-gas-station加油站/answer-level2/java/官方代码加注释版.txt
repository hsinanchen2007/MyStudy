### 解题思路
对leetcode官方代码 加了自己注释
便于理解～

### 代码

```java
class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        //贪心算法

        //加油站的个数
        int n = gas.length;

        //存环绕一周油箱所剩的油量，如果此值小于0 则不能环绕一周
        int total_tank = 0;
        
        //当前节点出发的剩余油量 每走一步需要判断当前值是否小于0 小于0则选择下一个开始的油箱
        int curr_tank = 0;

        //开始位置 默认为0
        int starting_station = 0;

        for (int i = 0; i < n; ++i) {

            //走到i时油箱剩余的油量
            total_tank += gas[i] - cost[i];

            //从starting_station出发 走到i节点时 剩余的油量
            curr_tank += gas[i] - cost[i];
           
            //如果当前的油量小于0时，则starting_station赋值为下一位，同时当前油量清0
            if (curr_tank < 0) {
                 starting_station = i + 1; 
                 curr_tank = 0;
            }
        }

        //最后判断总油量是否小于0 小于0 肯定不能环绕一圈 否则返回一次遍历所找到的油量位置
        return total_tank >= 0 ? starting_station : -1;
    }
}
```