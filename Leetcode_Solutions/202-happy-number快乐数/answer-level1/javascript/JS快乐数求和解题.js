### 解题思路
每次求和放入Set中。如果set历史中有本次求和值。说明不符合快乐数要求。

### 代码

```javascript
/**
 * @param {number} n
 * @return {boolean}
 */
var isHappy = function(n) {
    let set = new Set();
    let numStr = ""+n;
    let sum;
    while(sum !== 1){
        sum = 0;
        for(let i = 0;i<numStr.length;i++){
            sum += Number(numStr[i])*Number(numStr[i]);
        }
        numStr = ""+sum;
        if(set.has(sum))
            return false;
        set.add(sum);
    }
    return true;
};
```