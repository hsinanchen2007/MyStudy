### 解题思路
通过回溯算法 + 剪枝 + DFS 实现
![WechatIMG298.png](https://pic.leetcode-cn.com/956ce0288fd39336d85a883ab1c68e7251996f4264ff6db31ffaf02f21c7f84b-WechatIMG298.png)

### 代码

```javascript
/**
 * @param {number} n
 * @return {string[]}
 */
var generateParenthesis = function(n) {
    var list = []
    if ( n == 0) {
        return 
    }
    dfs('', n, n, list)

    function dfs(str, left, right, list) {
        if (left == 0 && right == 0) {
            list.push(str)
            return list
        }
        if (left > 0) {
            dfs(str + '(', left - 1, right, list)
        }

        if (right > 0 && left < right) {
            dfs(str + ')', left, right - 1, list)
        }
    }

    return list
};
```