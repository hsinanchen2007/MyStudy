### 解题思路
模拟汽车的走法，时间复杂度 O(N2)

### 代码

```java
class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        for(int i = 0; i < gas.length; i++) {
            int fuel = gas[i];
            if(fuel < cost[i]) continue;
            if(canAround(gas,cost,i)) return i;
        }
        return -1;
    }
    private static boolean canAround(int[] gas,int[] cost,int i) {
        int cur = i;
        int curFuel = gas[cur];
        while (cur != ((i == 0) ? gas.length-1: i-1)) {
            int next = (cur+1 == gas.length) ? 0: cur+1;
            curFuel +=  -cost[cur] + gas[next];
            if(curFuel < cost[next]) return false;
            else {
                cur++;
                if(cur == gas.length) {
                    // 如果碰到末尾，直接置 0
                    cur = 0;
                }
            }
        }
        return curFuel >= cost[cur];  
    }
}
```