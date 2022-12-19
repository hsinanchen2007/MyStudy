### 解题思路
动态规划

### 代码

```javascript
/**
 * @param {number[]} cost
 * @return {number}
 */
var minCostClimbingStairs = function(cost) {
    let memory = {}
    memory[0] = cost[0]
    memory[1] = cost[1]
    for(let i=2; i<cost.length; i++) {
        memory[i] = Math.min(memory[i-1],memory[i-2])+cost[i]
    }
    return Math.min(memory[cost.length-1],memory[cost.length-2])
};
```