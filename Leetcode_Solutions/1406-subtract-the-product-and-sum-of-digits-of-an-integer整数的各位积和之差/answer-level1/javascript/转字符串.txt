### 解题思路
将数字转成字符串然后每一位相加、相乘求商

### 代码

```javascript
/**
 * @param {number} n
 * @return {number}
 */
var subtractProductAndSum = function(n) {
    var sum = 0;
    var ji = 1;
    n = n.toString();
    var nl = n.length;
    for(let i=0;i<nl;i++) {
        sum = sum + parseInt(n[i]);
        ji = ji * parseInt(n[i]);
    }
    return ji - sum;
};
```