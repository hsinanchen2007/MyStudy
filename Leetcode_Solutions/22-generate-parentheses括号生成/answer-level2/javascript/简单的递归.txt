### 解题思路
考虑两个因素, 一个是剩余的当前剩余匹配左括号, 一个是是否耗尽n个左括号.
比如在任意匹配时时, 有两种选择:
1. 如果有待匹配的左括号, 下一个能为右括号
2. 如果左括号的数量未到n个, 下一个还能未左括号

### 代码

```javascript
/**
 * @param {number} n
 * @return {string[]}
 */
var generateParenthesis = function(n) {
    const res = []
    function recur(current, left, remain) {
        // 如果多余的左括号并且已经耗尽了n个括号, 就是结果了, 推进res
        if(remain === 0 && left === 0) {
            return res.push(current)
        }
        // 如果还有多余的左括号, 则可以推右括号
        if(left > 0) {
            recur(current + ')', left-1, remain)
        }
        // 如果还没耗尽n个左括号, 则还可以推左括号
        if(remain > 0) {
            recur(current + '(', left + 1, remain - 1)
        }
    }
    // 必从'('开始, 其实也可以recur('', 0, n)来调用, 就会多一层
    recur('(', 1, n-1)
    return res
};
```