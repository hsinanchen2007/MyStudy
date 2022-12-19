因为将第 i 个筹码向左或者右移动 2 个单位，代价为 0。所以可以想象先把所有筹码移动0，或者1的位置。
那么剩下的就是看0的位置筹码多，还是1的位置筹码多。

```
class Solution {
    public int minCostToMoveChips(int[] chips) {
        int count1 = 0, count2 = 0;
        for (int i: chips) {
            count1 += i%2;
            count2 += (i+1)%2;
        }
        return Math.min(count1, count2);
    }
}
```
