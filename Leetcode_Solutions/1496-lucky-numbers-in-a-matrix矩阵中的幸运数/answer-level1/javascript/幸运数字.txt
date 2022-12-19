用LuckyNum作为数组记录幸运数字，用min作为变量记录最小数字，记录索引,然后查找它是不是本列最大的数字，是的话就放入min数组里，作为幸运数字
```
var luckyNumbers = function (matrix) {
    let LuckyNum = [];
    let fun = (min, y) => {
        for (var x = 0; x < matrix.length; x++) {
            if (x != i && min < matrix[x][y]) {
                return false
            }
        }
    }
    for (var i = 0; i < matrix.length; i++) {
        let min = Math.min(...matrix[i])
        let y = matrix[i].indexOf(min)
        if (!(fun(min, y) === false)) {
            LuckyNum.push(min)
        }
    }
    return LuckyNum
};
```
