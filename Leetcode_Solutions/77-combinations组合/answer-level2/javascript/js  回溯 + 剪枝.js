![图片.png](https://pic.leetcode-cn.com/b855e5f0cd25ceaef2ff734027cac70db0197313b9181f384819ff7d2bc059dd-%E5%9B%BE%E7%89%87.png)

```
/**
 * @param {number} n
 * @param {number} k
 * @return {number[][]}
 */
var generateCombine = function(n ,k, cur, res, start) {
    if(cur.length === k) {
        res.push([].concat(cur))
        return
    }

    for(let i = start; i<= n - (k - cur.length) + 1; i++) {
        cur.push(i)
        generateCombine(n, k, cur, res, i + 1)
        cur.pop()
    }
    return
}
var combine = function(n, k) {
    if(n <= 0 || k <= 0 || k > n) {
        return []
    }
    let cur = [], res = []
    generateCombine(n, k, cur, res, 1)
    return res
};
```
