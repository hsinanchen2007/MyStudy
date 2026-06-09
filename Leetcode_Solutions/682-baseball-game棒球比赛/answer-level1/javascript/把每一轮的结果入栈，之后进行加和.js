把每一轮的结果入栈，之后进行加和

```
/**
 * @param {string[]} ops
 * @return {number}
 */
var calPoints = function(ops) {
    // 使用 栈
    let result = []
    ops.forEach(item => {
        switch (item) {
            case 'C':
                if(result.length > 0) {
                    result.pop()
                }
                break
            case 'D':
                if(result.length > 0) {
                    let pre = result.pop()
                    result.push(pre, pre * 2)
                }
                break
            case '+':
                if(result.length == 1) {
                    let pre1 = result.pop()
                    result.push(pre1, pre1)
                } else if (result.length >1) {
                    let pre1 = result.pop()
                    let pre2 = result.pop()
                    result.push(pre2, pre1, pre1 + pre2)
                }
                break
            default:
                result.push(Number(item))
        }
    })
    return result.reduce((a, b) => {return a + b})
};
```
