
![image.png](https://pic.leetcode-cn.com/6810b059f26b7847f100f97a646788603668b2219ea2b9b0886e7df7c18f2339-image.png)

```
/**
 * @param {string} s
 * @return {string}
 */
var minRemoveToMakeValid = function(s) {
    // 解题思路：栈
    // 两次循环
    // 1. 循环s解决无效的'(' 得到t
    // 2. 循环t解决无效的')' 得到r
    let stack = [], t = '', r = '';
    for(let i = 0; i < s.length; i++) {
        if('(' === s[i]) {
            stack.push(s[i]);
            t+=s[i];
        } else if(')' === s[i]) {
            if(stack.length) {
                t+=s[i];
                stack.pop();
            }
        } else {
            t+=s[i];
        }
    }
    stack.length = 0;
    for(let i = t.length - 1; i >= 0; i--) {
        if(')' === t[i]) {
            stack.push(t[i]);
            r= t[i] + r;
        } else if('(' === t[i]) {
            if(stack.length) {
                r= t[i] + r;
                stack.pop();
            }
        } else {
            r= t[i] + r;
        }
    }
    return r;
};
```
