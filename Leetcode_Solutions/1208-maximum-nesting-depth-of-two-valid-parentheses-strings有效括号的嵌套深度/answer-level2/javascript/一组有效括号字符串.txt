### 解题思路
1. 获取有效括号字符串的字符嵌套深度，当字符是'('时，压入栈，且深度+1；当字符是')'时，深度不变，且弹出栈。
2. 将偶数深度分配给A，将奇数深度分配给B。
### 代码

```javascript
/**
 * @param {string} seq
 * @return {number[]}
 */
var maxDepthAfterSplit = function(seq) {
    let dep = 0;
    return seq.split("").map((value, index) => {
        if (value === '(') {
            ++dep;
            return dep % 2;
        } else {
            let ans = dep % 2;
            --dep;
            return ans;
        }
    });
};
```