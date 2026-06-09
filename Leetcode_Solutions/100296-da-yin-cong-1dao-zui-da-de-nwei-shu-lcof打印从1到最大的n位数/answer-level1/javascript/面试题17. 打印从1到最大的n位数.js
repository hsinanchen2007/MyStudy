### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number} n
 * @return {number[]}
 */
var printNumbers = function(n) {
    let result = [], len = Math.pow(10, n)
    for(let i = 1; i < len; i++){
        result.push(i)
    }
    return result
};
```