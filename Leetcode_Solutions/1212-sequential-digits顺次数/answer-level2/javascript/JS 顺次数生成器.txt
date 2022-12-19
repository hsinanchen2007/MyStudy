### 解题思路
创建一个生成器函数用于生成处于 low 和 high 位数之间的顺次数（菜鸟一只，欢迎各位提意见）

### 代码

```javascript
/**
 * @param {number} low
 * @param {number} high
 * @return {number[]}
 */
var sequentialDigits = function(low, high) {
    let lowDigit = (low).toString().length
    let highDigit = (high).toString().length
    let startNum = 1
    let current = 0
    let res = []
    while(1) {
        current = generateNum(lowDigit, startNum)
        if(current < 0) {
            if(lowDigit >= highDigit) {
                break
            }else {
                lowDigit++
                startNum = 1
            }
        }else {
            startNum++
        }
        if(current >= low && current <= high) {
            res.push(current)
        }
    }
    return res
    
    function generateNum (digit, start) {
        if(digit > 10-start) {
            return -1
        }
        let temp = ""
        while(digit > 0) {
            temp += start
            start++
            digit--
        }
        return parseInt(temp)
    }
};
```