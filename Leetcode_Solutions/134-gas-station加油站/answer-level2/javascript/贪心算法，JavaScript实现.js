### 解题思路
思路在代码中

### 代码

```javascript
/**
 * @param {number[]} gas
 * @param {number[]} cost
 * @return {number}
 */
var canCompleteCircuit = function(gas, cost) {
    //思路：贪心算法，每个加油站我都把加油站的油加到车里；
    //首先找到所有能作为起点的加油站（也就是当前加油站存储的油量支持我走到下一站 gas[i] >= cost[i]），位置放到originalingStation中
    //遍历每个起点加油站，看它作为起点是否能走一圈，storage存储量，consumption消耗量，while循环，存储量要一直大于等于消耗量，而且最多走一圈（不然会出现死循环）
    //等到条件不满足退出while时，判断当前是否安稳走了一圈，若是直接返回位置即可，若不是找下一个出发点
    //若出发点都不满足（for循环走到头），则返回-1
    let originalingStation = [];
    const len = gas.length;
    for(let i = 0; i < len; i ++) {
        if(gas[i] >= cost[i]) originalingStation.push(i);
    }

    const originalLen = originalingStation.length;
    if(!originalingStation.length) return -1;
    for(let i = 0; i < originalLen; i ++) {
        let x = originalingStation[i];
        let storage = gas[x],//存储量
            consumption = cost[x];//消耗量
        let j = (x >= len - 1) ? 0 : x + 1;
        while(storage >= consumption && j !== x) {
            storage += gas[j];
            consumption += cost[j];
            j = (j >= len - 1) ? 0 : j + 1;
        }
        if(j === x && storage >= consumption) return j;
    }
    return -1;
};
```