### 解题思路
执行用时在所有 JavaScript 提交中击败了99.25%的用户
内存消耗在所有 JavaScript 提交中击败了100.00%的用户

### 代码

```javascript
var printNumbers = function (n) {
    if (n === 0) return [];
    let result = [];
    for (let i = 1; i < Math.pow(10,n); i++) {
        result.push(i)
    }
    return result
};
```