### 解题思路

- 对 ``g`` 和 ``s`` 两个数组按「从大到小」排序
- 如果当前的孩子喂不饱，那么用后面的饼干肯定也喂不饱，所以直接跳过这个孩子（当前拿最大的饼干喂胃口最大的孩子）
- 如果当前的孩子喂得饱，那么用这块饼干喂饱他，然后看下一个胃口最大的孩子，重复上面的步骤

### 代码

```javascript
/**
 * @param {number[]} g
 * @param {number[]} s
 * @return {number}
 */
var findContentChildren = function(g, s) {
    let i = 0
    let j = 0
    // 按从大到小来排序
    g.sort((a, b) => b - a)
    s.sort((a, b) => b - a)
    while (i < g.length && j < s.length) {
        // 如果目前最大的饼干还不能满足
        // 那么就喂不饱他了，直接跳过
        // 否则 + 1
        if (g[i] > s[j]) {
            i++
        } else {
            i++
            j++
        }
    }
    // 返回结果
    return j
};
```