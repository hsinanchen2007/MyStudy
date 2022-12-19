### 执行结果
![image.png](https://pic.leetcode-cn.com/48bbef2f33bf2c854d5fc818da9121997457415548cdcd130eff74a393a45932-image.png)

### 解题思路
利用栈。
遇到左括号，一律推入栈中，
遇到右括号，将栈顶部元素拿出，如果不匹配则返回 false，如果匹配则继续循环。

为了提高性能, 在循环前进行这一步：`let len = s.length`是非常关键的，减少了计算次数。
为了提高执行时间，这一步`if (len%2) return false`是非常关键的，减少了不必要的计算。

### 代码

```javascript
/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(s) {
    let arr = []
    let len = s.length
    if (len%2) return false
    for (let i = 0; i < len; i++) {
        let letter = s[i]
        switch(letter) {
            case "(": {
                arr.push(letter)
                break;
            }
            case "[": {
                arr.push(letter)
                break;
            }
            case "{": {
                arr.push(letter)
                break;
            }
            case ")": {
                if (arr.pop() !== "(") return false
                break;
            }
            case "]": {
                 if (arr.pop() !== "[") return false
                break;
            }
            case "}": {
                if (arr.pop() !== "{") return false
                break;
            }
        }
    }
    return !arr.length

};
```