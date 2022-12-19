### 解题思路
滑动窗口找到连续数的两个顶点，生成数组push进结果

### 代码

```javascript
/**
 * @param {number} target
 * @return {number[][]}
 */
var findContinuousSequence = function(target) {
    let l = 0, r = 0
    const len = Math.ceil(target / 2)
    const res = []
    const sum = (l, r) => (l + r) / 2 * (r - l + 1)
    while (r <= len) {
        l++
        while (sum(l, r) < target) {
            r++
        }
        if ((sum(l, r)) === target) {
            res.push(Array(r - l + 1).fill().map((item, index) => index + l))
        }
    }
    return res
};
```