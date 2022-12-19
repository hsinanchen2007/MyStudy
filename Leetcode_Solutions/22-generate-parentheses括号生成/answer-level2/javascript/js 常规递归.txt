js 常规递归
```js
var generateParenthesis = function(n) {
    const res = [];
    function dfs(left, right, path) {
        if (left < 0 || right < 0 || left > right) return;
        if (!left && !right) {
            res.push(path);
            return;
        }
        dfs(left - 1, right, path + '(');
        dfs(left, right - 1, path + ')');
    }
    dfs(n, n, '');
    return res;
};
```
