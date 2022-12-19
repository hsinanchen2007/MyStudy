### 解题思路
画出递归树，找到规律即可。
![image.png](https://pic.leetcode-cn.com/cbb6a0d57449d049b3698d5d4176f6dd895547d8849c1fc68d0aa65f2514f5a7-image.png)


### 代码

```javascript
/**
 * @param {number} n
 * @return {string[]}
 */
var generateParenthesis = function(n) {
    const dfs = (left, right, str) => {
        if (left === 0 && right === 0) {
            res.push(str)
            return
        }
        // 只要 ( 还有剩，那么递归 (
        if (left > 0) {
            dfs(left - 1, right, str + '(')
        }
        // 如果 ) 的剩余的数量大于 ( 的剩余的数量，那么递归 )
        if (right > left) {
            dfs(left, right - 1, str + ')')
        }
    }
    let res = []
    dfs(n, n, '')
    return res
};
```