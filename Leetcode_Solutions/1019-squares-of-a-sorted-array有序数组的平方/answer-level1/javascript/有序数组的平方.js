
```javascript []
var sortedSquares = function (A) {
    return A.map(res => {return res * res}).sort((a, b) => { return a - b })
};

console.log(sortedSquares([-4, -1, 0, 3, 10]))

/**
 * 解题思路：
 * 
 * 1. 先计算数组每一项的平方，在将数组进行排序
 */
```

