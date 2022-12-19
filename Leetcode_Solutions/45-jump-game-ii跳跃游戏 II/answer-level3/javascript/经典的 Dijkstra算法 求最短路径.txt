# 经典的 Dijkstra算法 求最短路径
将这个问题换一个角度理解：
- 每个位置可以跳跃的长度看作是出度，比如位置 i 的值为2，表示有 i->i+1, i->i+2 两条有向边
- 整个数组可以画成一张有向图，同时也是拓扑有序图
- 求最小跳跃次数，就是求最短路径长度

## 算法
构建一个距离向量，从终点开始进行动态规划，逐个更新每个位置到终点的最短路径长度。因为这里的图是拓扑有序的，因此只需要逆序遍历一次就可以

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var jump = function(nums) {
    if (nums.length <= 1) {
        return 0;
    }
    // dijkstra ?
    let cost = new Int32Array(nums.length);
    for (let i=nums.length-2;i>=0; i--) {
        let min = nums.length;
        for (let j=nums[i];j>0;j--) {
            if (i+j>=nums.length) {
                continue;
            }
            min = Math.min(min, cost[i+j]+1);
            if (cost[i+j] == 0) {
                break; // 直达终点    
            }
        }
        cost[i] = min;
    }
    return cost[0];
};
```
