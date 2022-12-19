```js
//我的答案
var lastRemaining = function(n, m) {
    const arr = [...new Array(n).keys()]
    while (n > 1) {
        for (let i = 0; i < m - 1; i++) {
            arr.push(arr.shift())
        }
        arr.shift()
        n --
    }
    return arr[0]
};
// 解题思路
// 将圆看作队列，每次标记都将被标记数字移动到队列后面，再执行删除
// 比如：5, 5
// 1 2 3 4 5 （去5）
// 1 2 3 4 1 （去1）
// 2 3 4 2 3 （去3）
// 2 4 2 4 2 （去2）
// 剩下4
```
