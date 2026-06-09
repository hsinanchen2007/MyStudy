### 解题思路
深度优先遍历 dfs
### 代码

```javascript
/**
 * @param {number} n
 * @return {string[]}
 */
var generateParenthesis = function(n) {
    let ans = []
    function dfs(left, right, cur) {
        // console.log(left, right, cur)
        if(left < 0 || right < 0) return
        if(left == 0 && right == 0) {
            ans.push(cur)
            return
        }
        if(right == left) {
            dfs(left - 1, right, cur + '(')
        }
        if (left < right) {
            dfs(left - 1,right, cur + '(')
            dfs(left,right - 1, cur + ')')
        }
    }
    dfs(n, n, '')
    return ans
};
```