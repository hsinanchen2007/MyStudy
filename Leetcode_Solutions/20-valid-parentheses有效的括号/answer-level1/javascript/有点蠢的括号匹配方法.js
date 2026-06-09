### 解题思路
大致思路是与官方题解相同的，在括号匹配的方法上自己只想到了这种略蠢的方式，欢迎分享更简单的奇思妙想。
- **其实就是利用正负数的关系表示括号的匹配规则**

### 代码

```javascript
/**
 * @param {string} s
 * @return {boolean}
 */

var isValid = function(s) {
    let stack = [];
    let obj = {
        '(': -1,
        ')': 1,
        '{': -2,
        '}': 2,
        '[': -3,
        ']': 3
    };
    for(let i = 0; i < s.length; i++) {
        if(obj[s[i]] < 0) {
           stack.push(s[i]);
        } else {
            let last = stack[stack.length - 1];
            if(obj[last] + obj[s[i]] === 0) {
                stack.pop();
            } else {
                return false;
            } 
        }   
    }
    if(stack.length !== 0) {
        return false;
    }
    return true;
};
```