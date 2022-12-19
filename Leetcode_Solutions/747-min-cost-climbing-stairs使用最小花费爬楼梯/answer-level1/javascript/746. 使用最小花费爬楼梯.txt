### 解题思路
最后的台阶由f(n-1)和f(n-2)这两个倒数第二个阶梯爬上来。
从n-1和n-2爬到顶楼的代价是0，故min(f(n-1), f(n-2)) + 0。
找到规律：
f(0) = cost[0];
f(1) = cost[1];
f(2) = min(f(0), f(1)) + cost[2];
....
f(n) = min(f(n-2), f(n-1)) + cost[n];

如此求得爬到每一层阶梯所花的最小代价。
最后判断一下，返回爬到顶楼的最小代价即可。

### 代码

```javascript
/**
 * @param {number[]} cost
 * @return {number}
 */
var minCostClimbingStairs = function(cost) {
    let len = cost.length;
    let f = new Array(len);
    f[0] = cost[0];
    f[1] = cost[1];

    for (let i=2; i<len; ++i) {
        f[i] = (f[i-1] < f[i-2] ? f[i-1] : f[i-2]) +cost[i];
    }

    return f[len-1] > f[len-2] ? f[len-2] : f[len-1];
};
```