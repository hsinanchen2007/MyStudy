### 解题思路
1. 剪枝： 当前可用的(个数m和当前可用的)个数小于0 or 当前output中)个数大于(的个数；
2. 递归边界：m ===0 && n === 0，加入res中；
3. 继续搜索：加上( or )，减去对应的m or n

### 代码

```javascript
/**
 * @param {number} n
 * @return {string[]}
 */
var generateParenthesis = function(n) {
    let res = [];
    dfs(n, n, '', res);
    return res;
};

function dfs(m, n, output, res) {
    if(m > n || m < 0 || n < 0) return;
    if(m === 0 && n === 0) res.push(output);
    dfs(m - 1, n, output + '(', res);
    dfs(m, n - 1, output + ')', res);
}
```