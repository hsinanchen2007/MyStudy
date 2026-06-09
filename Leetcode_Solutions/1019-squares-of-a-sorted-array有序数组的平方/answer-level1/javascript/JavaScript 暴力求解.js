### 解题思路
- 通过 Array.map()遍历数组，并通过 Math.pow() 对每一个项做平方
- 通过 sort() 进行排序

### 代码

```javascript
/**
 * @param {number[]} A
 * @return {number[]}
 */
var sortedSquares = function(A) {
    let arr = []
    arr = A.map(item => Math.pow(item,2))
    return arr.sort((a,b) => a - b)
};
```