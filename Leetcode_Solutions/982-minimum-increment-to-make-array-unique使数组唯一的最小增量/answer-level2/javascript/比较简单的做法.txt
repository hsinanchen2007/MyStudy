### 解题思路
首先遍历数组 统计每个值的数量 并找出最大值和最小值 从最小值开始move 每次move 当前值数量 - 1，最大值是为了保证所有值都是唯一

### 代码

```javascript
/**
 * @param {number[]} A
 * @return {number}
 */
var minIncrementForUnique = function(A) {
    var map = {}
    let min = 4000, max = 0;
    A.forEach(i => {
        if(i < min) min = i;
        if(i > max) max = i;
        if(map[i] != undefined){
            map[i] ++;
        }else {
            map[i] = 1;
        }
    })
    var value,count = 0;
    value = min;
    count = map[min];
    let flag = true;
    let move = 0;
    while(count > 0 || value < max){
        let remain = count == 0 ? 0 : count - 1;
        move += remain;
        value ++;
        count = (map[value] || 0) + remain
    }
    return move;
};
```
