### 解题思路
![image.png](https://pic.leetcode-cn.com/1e9c9513227db9818cad478f07d8a73aab78ce9cb9e1bd55ab31f3b0dad99b33-image.png)

就除法的时候要考虑下取整。

### 代码

```javascript
/**
 * @param {string[]} tokens
 * @return {number}
 */
var evalRPN = function(tokens) {
    let st = [],
        cal = "+-*/";

    tokens.forEach(val => {
        if (!cal.includes(val)) {
            st.push(parseInt(val, 10));
        } else {
            let p2 = st.pop(),
                p1 = st.pop(),
                res = 0;
            if (val === "+") {
                res = p1 + p2;
            } else if (val === "-") {
                res = p1 - p2;
            } else if (val === "*") {
                res = p1 * p2;
            } else {
                res = p1 / p2 > 0 ? Math.floor(p1 / p2) : Math.ceil(p1 / p2);
            }
            st.push(res);
        }
    });
    return st[0];
};
```