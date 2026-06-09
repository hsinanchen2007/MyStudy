18行，写得还是有点多
![123.png](https://pic.leetcode-cn.com/b9fb720678d527b5d0737810b7a64c60637df847f3d8993a6aa239255cfc4346-123.png)
```js
/**
 * @param {string} s
 * @return {string[]}
 */
var permutation = function(s) {
    const res = new Set();
    function dfs(s, i, len) {
        if (i === s.length) {
            res.add(s);
            return;
        }
        for(let j = i; j < s.length; j++) {
            s = swap(s, i, j);
            dfs(s, i + 1, len);
            s = swap(s, i, j);
        }
    }
    function swap(str, i, j) {
        if (i === j) return str;
        return str.substring(0, i) + str[j] + str.substring(i + 1, j) + str[i] + str.substring(j + 1);
    }
    dfs(s, 0, s.length);
    return Array.from(res);
};
```
