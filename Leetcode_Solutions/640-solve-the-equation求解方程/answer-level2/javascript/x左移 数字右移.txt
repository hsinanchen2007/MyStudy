#### x左移 数字右移

```javascript
/**
* @param {string} equation
* @return {string}
*/
var solveEquation = function (equation) {
    let preExec = '+',//add sub num
        equd = false, xCount = 0, totalNum = 0
    preNum = 0
    for (let i = 0, len = equation.length; i < len; i++) {
        let ch = equation[i]
        if (['+', '-', '='].indexOf(ch) > -1) {
            //+ - =，计算终止
            if (equd) {
                if (preExec === '+') {
                    totalNum += new Number(preNum)
                } else {
                    totalNum -= new Number(preNum)
                }
            } else {
                if (preExec === '+') {
                    totalNum -= new Number(preNum)
                } else {
                    totalNum += new Number(preNum)
                }
            }
            preNum = 0
            preExec = ch === '-' ? '-' : '+'
            if (ch === '=') {
                equd = true
            }
        }
        if (ch === 'x') {
            if (equd) {
                //等式右边
                if (preExec === '+') {
                    xCount -= new Number(preNum || 1)
                } else if (preExec === '-') {
                    xCount += new Number(preNum || 1)
                }
            } else {
                //等式左边
                if (preExec === '+') {
                    xCount += new Number(preNum || 1)
                } else if (preExec === '-') {
                    xCount -= new Number(preNum || 1)
                }
            }
            preNum = 0
        }

        if (!isNaN(ch)) {
            preNum = preNum + '' + ch
            if (i === len - 1) {
                if (equd) {
                    if (preExec === '+') {
                        totalNum += new Number(preNum)
                    } else {
                        totalNum -= new Number(preNum)
                    }
                } else {
                    if (preExec === '+') {
                        totalNum -= new Number(preNum)
                    } else {
                        totalNum += new Number(preNum)
                    }
                }
            }
        }
    }
    if (xCount === 0 && totalNum === 0) {
        return "Infinite solutions"
    }
    if (xCount === 0) {
        return "No solution"
    }
    if (xCount === 1) {
        return 'x' + '=' + totalNum
    }
    return 'x' + '=' + parseInt(totalNum/xCount)
};
```