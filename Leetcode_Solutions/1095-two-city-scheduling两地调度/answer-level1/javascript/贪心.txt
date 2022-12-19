思路来自[官方题解](https://leetcode-cn.com/problems/two-city-scheduling/solution/er-cha-shu-de-chui-xu-bian-li-by-leetcode/)
执行用时 :68 ms, 在所有 JavaScript 提交中击败了100.00%的用户
内存消耗 :35 MB, 在所有 JavaScript 提交中击败了100.00%的用户

```javascript
var twoCitySchedCost = function(costs) {
    costs.sort((o1, o2) => {
        return o1[0]-o1[1]-(o2[0]-o2[1]);
    });
    // console.log(costs);
    let sum = 0;
    let middle = Math.floor(costs.length/2);
    for(let i = 0; i < middle; i++){
        sum += costs[i][0];
    }
    for(let i = middle; i < costs.length; i++){
        sum += costs[i][1];
    }
    return sum;
};
```
