题目为每次可以选择爬一个或者两个楼梯，然后在倒数第一个楼梯或者最后一个楼梯可以上楼，为了计算方便，直接在数组末尾添加一个0作为楼梯的顶部。

设定一个新的数组保存到当前楼梯所需的最少花费。

由于你到达了当前楼梯，因此每一个当前点的最少花费都需要加上当前点的花费。

然后前两个的最低花费分别是他们自身 

[0]的时候花费就是cost[0]

[1]的时候花费为cost[0]+cost[1]或者cost[1]，因此取最小必为cost[1]

```
// 执行用时 : 88 ms, 在Min Cost Climbing Stairs的JavaScript提交中击败了97.26% 的用户
// 内存消耗 : 35.7 MB, 在Min Cost Climbing Stairs的JavaScript提交中击败了39.13% 的用户
/**
 * @param {number[]} cost
 * @return {number}
 */
// 由于是爬楼梯， 因此如果你到达了当前格子， 就必须加上当前格的权重。 由于爬梯可以选择1步或者2步走。
// 因此到达当前格的最小值为Math.min(temp[i - 2], temp[i - 1])
var minCostClimbingStairs = function (cost) {
  cost.push(0)
  let l = cost.length;
  let temp = [cost[0], cost[1]]
  for (let i = 2; i < l; i++) {
    temp[i] = cost[i] + Math.min(temp[i - 2], temp[i - 1])
    // console.log(temp)
  }
  return temp[l - 1]
};
```