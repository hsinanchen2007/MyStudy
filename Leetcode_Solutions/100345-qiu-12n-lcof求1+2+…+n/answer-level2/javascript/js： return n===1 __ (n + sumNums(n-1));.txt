### 解题思路
n===1 || (n + sumNums(n-1));
这句如果n===1为真，后面的就不用执行，直接范围true；不为真，就执行后面的(n + sumNums(n-1))，并且返回式子结果，式子===0为false,！==0为true

这里其实就是隐式的使用了 分支判断

### 代码

```javascript
/**
 * @param {number} n
 * @return {number}
 */
var sumNums = function(n) {

    return n===1 || (n + sumNums(n-1));
};
```