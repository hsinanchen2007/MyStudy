1. 递归
```js
/**
 * @param {number} numRows
 * @return {number[][]}
 */
var generate = function(numRows) {
    function fn(i, j){ // i：行数，j：列数
        let r = (j==0 || i==j)
            ? 1
            : (resMap[`${i-1},${j}`] || fn(i-1, j)) + (resMap[`${i-1},${j-1}`] || fn(i-1, j-1))
        resMap[`${i},${j}`] = r // 使用对象把值存起来，就不用计算多次了，类似斐波那契数列
        return r
    }
    let res = [], resMap = {}
    for(let i=0;i<numRows;i++){
        let a = []
        for(let j=0;j<=i;j++) a.push(fn(i,j))
        res.push(a)
    }
    return res
};
```

2. 非递归
```js
/**
 * @param {number} numRows
 * @return {number[][]}
 */
var generate = function(numRows) {
    let res = [], resMap = {}
    for(let i=0;i<numRows;i++){
        let a = []
        for(let j=0;j<=i;j++){
            (j==0 || i==j) 
                ? a.push(1)
                : a.push(res[i-1][j-1] + res[i-1][j])
        }
        res.push(a)
    }
    return res
};
```


> 其实两种解法类似，非递归只是把结果从res取出来。