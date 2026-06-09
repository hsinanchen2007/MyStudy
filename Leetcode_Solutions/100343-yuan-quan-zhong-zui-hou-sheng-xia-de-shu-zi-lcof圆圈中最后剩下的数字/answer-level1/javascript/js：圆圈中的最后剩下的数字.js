### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number} n
 * @param {number} m
 * @return {number}
 */
var lastRemaining = function(n, m) {
    let i = 0;
    let arr = [];
    for (let i = 0; i < n; i++){
        arr[i] = i;
    }
    for(i = (m-1) % arr.length; arr.length > 1; ){
        arr.splice(i, 1);
        i = (i + m - 1) % arr.length;
    }
    return arr[i];
};
```