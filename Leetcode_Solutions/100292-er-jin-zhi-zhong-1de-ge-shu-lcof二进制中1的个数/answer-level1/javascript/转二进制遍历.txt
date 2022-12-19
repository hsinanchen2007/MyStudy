### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number} n - a positive integer
 * @return {number}
 */
var hammingWeight = function(n) {
   return Array.prototype.reduce.call(n.toString(2), (num, item) => {
        if (item === '1') {
            return num += 1;
        }
        return num;
    }, 0)
};
```