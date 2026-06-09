### 解题思路
正确的括号必须满足 2 个条件: 
1. 左括号 < n
2. 添加右括号时，左括号数量必须大于右括号数量，并且右括号 < n



### 代码

```javascript
/**
 * @param {number} n
 * @return {string[]}
 */
var generateParenthesis = function(n) {
    let ans = [];
    helper(0, 0, n, '', ans);
    return ans;
};

function helper (left, right, n, s, ans) {
    // termination
    if (left == n && right == n) {
        return ans.push(s);
    }
    // process
    // drill down
    if (left < n) helper (left + 1, right, n, s + '(', ans);
    if (right < left) helper (left, right + 1, n, s + ')', ans);
    // reverse status
}
```