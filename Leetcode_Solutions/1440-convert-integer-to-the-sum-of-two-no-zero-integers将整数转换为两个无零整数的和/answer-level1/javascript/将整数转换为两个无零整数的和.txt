### 解题思路

遍历找出两个数和为 `n`，并且都不包含 `0` 的数。

### 代码

```javascript
/**
 * @param {number} n
 * @return {number[]}
 */
var getNoZeroIntegers = function(n) {
    for(let i = 1; i < n; i++){
        let diff = n - i;
        if(!diff.toString().includes(0) && !i.toString().includes(0)){
            return [i, diff];
        }
    }
};
```