```
/**
 * @param {number[]} gas
 * @param {number[]} cost
 * @return {number}
 */
var canCompleteCircuit = function(gas, cost) {
    let totalGas = 0;
    let totalCost = 0;

    for(let i=0; i<gas.length; i++){
        totalGas = totalGas + gas[i]
        totalCost = totalCost + cost[i]
    }

    if(totalGas<totalCost){
        return -1;
    }
    let currentGas = 0;
    let start = 0;
    for(let i=0; i<gas.length; i++){
        currentGas = currentGas -cost[i] + gas[i];
        if(currentGas < 0) {
            currentGas = 0;
            start = i + 1;
        }
    }

    return start;
};
```
