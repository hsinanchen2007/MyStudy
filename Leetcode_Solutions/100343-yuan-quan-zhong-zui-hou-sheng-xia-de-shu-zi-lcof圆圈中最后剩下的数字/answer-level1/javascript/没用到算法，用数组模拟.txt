### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number} n
 * @param {number} m
 * @return {number}
 */

// 经典的约瑟夫环问题... 先放过... 用数组模拟整个流程 ...
var lastRemaining = function(n, m) {

    let arr = []
    for (let i = 0; i < n; i++) // initialize
        arr[i] = i

    let i = 0
    while (arr.length > 1) {
        //又是道算术题... 等有时间用数学归纳法推导一下...
        i = (i + m - 1) % arr.length 
        arr.splice(i, 1) // remove element
    }

    return arr[0]
};
```