```javascript
/**
 * @param {number[][]} costs
 * @return {number}
 */
var twoCitySchedCost = function(costs) {
    costs.sort((a, b) => a[0] - a[1] - b[0] + b[1])
    let mid = costs.length / 2
    let res = 0
    for (let i in costs) {
        if (i < mid) {
            res = res + costs[i][0]
        } else {
            res = res + costs[i][1]
        }
    }
    return res
};```