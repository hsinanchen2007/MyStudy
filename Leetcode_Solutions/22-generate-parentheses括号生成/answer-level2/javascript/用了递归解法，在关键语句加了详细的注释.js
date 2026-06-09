### 
- 执行用时 :56 ms, 在所有 JavaScript 提交中击败了96.77%的用户
- 内存消耗 :34.7 MB, 在所有 JavaScript 提交中击败了89.47%的用户
### 代码

```javascript
/**
 * @param {number} n
 * @return {string[]}
 */
var generateParenthesis = function (n) {
    let result = [] //创建一个存放字符串的数组
    let go = function (l, r, resultString) {
        if (resultString.length == 2 * n) { result.push(resultString); return } //当左右括号都达到n个时为递归的终点，把字符串push进result数组
        let s = resultString
        if (l < n) {//当左括号小于指定数量n时，可以继续加左括号
            go(l + 1, r, s + "(")
        }
        if (r < n && l > r) {//同理右括号也是一样，但是还有一个限制条件就是右括号必须小于左括号才能添加右括号，不然是无效的括号组合了
            go(l, r + 1, s + ")")
        }
        return
    }
    go(0, 0, "")//调用go方法，传入初始左右括号数各为0，初始空字符串“”
    return result
};
```