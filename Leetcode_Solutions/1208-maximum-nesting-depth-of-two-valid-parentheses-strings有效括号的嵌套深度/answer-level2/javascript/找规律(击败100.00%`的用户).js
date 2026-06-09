执行用时 : `68 ms` , 在所有 JavaScript 提交中击败了 `100.00%` 的用户
内存消耗 : `36.6 MB` , 在所有 JavaScript 提交中击败了 `100.00%` 的用户

### 解题思路
找规律，一共四种情况，不同情况，不同的操作

### 代码

```javascript
/**
 * @param {string} seq
 * @return {number[]}
 */
var maxDepthAfterSplit = function (seq) {
    let res = [];
    let last = ")";
    let flag = true;
    for (let i = 0; i < seq.length; i++) {
        if (seq.charAt(i) === "(" && last === "(") {
            flag = !flag;
            res.push(flag ? 0 : 1)
        } else if (seq.charAt(i) === ")" && last === "(") {
            res.push(flag ? 0 : 1)
            last=")"
        } else if (seq.charAt(i) === "(" && last === ")") {
            res.push(flag ? 0 : 1)
            last = "("
        } else if (seq.charAt(i) === ")" && last === ")"){
            flag = !flag;
            res.push(flag ? 0 : 1)
        }
    }
    return res
};
```