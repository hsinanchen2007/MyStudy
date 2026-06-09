### 解题思路
懒写case 所以空间复杂度超低的写法。。。

### 代码

```javascript
/**
 * @param {number[]} gas
 * @param {number[]} cost
 * @return {number}
 */
var canCompleteCircuit = function(gas, cost) {
    let greedy = []
    let cycleGas = [...gas, ...gas]
    let cycleCost = [...cost, ...cost]
    for(let i = 0; i < gas.length; i++) {
        let curGas = 0
        let j = i
        while(curGas >= 0 && j - i < gas.length) {
            curGas += cycleGas[j]
            curGas -= cycleCost[j]
            j++
        }
        if(j - i === gas.length && curGas >= 0) return i
    }
    return greedy.length > 0 ? greedy[0] : -1
};
```