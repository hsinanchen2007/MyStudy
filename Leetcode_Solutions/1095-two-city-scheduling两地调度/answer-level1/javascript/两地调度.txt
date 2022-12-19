```js
var twoCitySchedCost = function(costs) {
	// 让其以costs[0]-costs[1]的差值从小到大排序。
    costs.sort((a, b) => a[0] - a[1] - (b[0] - b[1]))
    let sum = 0;
    // 前一半取去A市，后一半取去B市，
    // 前一半是去A市最合适，后一半市去B市最合适。
    for (let i = 0; i < costs.length; i++) {
    	if (i < costs.length / 2) {
    		sum += costs[i][0]
    	} else {
    		sum += costs[i][1]
    	}
    }
    return sum
};
```
