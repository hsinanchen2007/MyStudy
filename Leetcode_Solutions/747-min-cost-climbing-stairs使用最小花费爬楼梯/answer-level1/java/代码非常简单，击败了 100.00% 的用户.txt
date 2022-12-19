### 解题思路
理解题意：
1. 注意题的意思的走到台阶的上边，即数组的外面，从数组外到数组内有两种情况，在length-1的位置走一步，和在length-2的位置走两步。所以我们求的是走到台阶length-1和length-2的最小值。
2. 那么走到n阶台阶的花费（注意不是题要的结果）f(n) = min(f(n-1),f(n-2))+cost[n]。这个很好理解，走到n阶台阶的花费为，n-1台阶走一步和n-2走两步在加n阶台阶的花费。

### 代码

```java
class Solution {
    public int minCostClimbingStairs(int[] cost) {
        int pre = 0;
        int cur = 0;
        for(int i = 0;i<cost.length;i++){
            int temp = cur;
            cur = Math.min(pre,cur)+cost[i];
            pre = temp;
        }
        return Math.min(pre,cur);
    }
}
```