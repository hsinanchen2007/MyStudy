### 解题思路
![image.png](https://pic.leetcode-cn.com/1de6ded29be3c72c17cd35c0eb30a2dfe4860b5f5664c1edd4c97428e4192873-image.png)



### 代码

```javascript
/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(s) {
    if (!s) return true;
    if (s.length === 1) return false;
    if (s.length % 2 === 1) return false;
    let hash = {
        '(': ')',
        '{': '}',
        '[': ']',
    },
    stack = [s[0]];
    for (let i = 1; i < s.length; i++) {
        if (hash[stack[stack.length - 1]] === s[i]) {
            stack.pop();
        } else {
            stack.push(s[i]);
            if (stack.length > s.length / 2) return false;
        }
    }
    return !stack.length;
};
```