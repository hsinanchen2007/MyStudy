### 解题思路
转为字符串，各项相加相乘，运算过程中注意转为数字

### 代码

```javascript
/**
 * @param {number} n
 * @return {number}
 */
var subtractProductAndSum = function(n) {
    let splitArray = n.toString();
    let count = 1;
    let total = 0;
    for(i=0;i<splitArray.length;i++) {
        count *= parseInt(splitArray[i]);
        total += parseInt(splitArray[i]);
    }
    return count - total;
};
```