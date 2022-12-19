```javascript []
var judgeCircle = function (moves) {
    let lrcount = 0
    let udcount = 0
    moves.split('').forEach(res => {
        switch(res) {
            case 'R':
                lrcount++
                break;
            case 'L':
                lrcount--
                break;
            case 'U':
                udcount++
                break;
            case 'D':
                udcount--
                break;
        }
    })
    return (lrcount === 0 && udcount === 0) ? true : false
};

/**
 * 解题思路：
 * 
 *  1. 为了避免冲突，我们使用两个变量来控制，一个是控制左右，一个是控制上下
 *  2 最后同时判断这两个变量是否为0
 */
```
