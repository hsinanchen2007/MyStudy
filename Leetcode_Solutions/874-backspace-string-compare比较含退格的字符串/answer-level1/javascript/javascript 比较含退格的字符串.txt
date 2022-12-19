### 解题思路
比较处理之后的结果，使用split转成数组，再用reduce处理成字符串

### 代码

```javascript
/**
 * @param {string} S
 * @param {string} T
 * @return {boolean}
 */
var backspaceCompare = function(S, T) {
    const reducer = (p, c) => {
        return c === '#' ? p.slice(0, -1) : p + c;
    };
    S = S.split('').reduce(reducer, '');
    T = T.split('').reduce(reducer, '');
    return  S=== T;
};
```