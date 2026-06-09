### 解题思路
思路为滑动窗口
生成tmp数组时采用了js提供的一些方法

### 代码

```javascript
/**
 * @param {number} target
 * @return {number[][]}
 */
var findContinuousSequence = function (target) {
    let res = []
    for (let l = 1, r = 2; l < r;) {
        let sum = (l + r) * (r - l + 1) / 2
        if (sum == target) {
            let tmp = (new Array(r - l + 1)).fill(0).map((v, index) => l + index);
            res.push(tmp)
            l++
        } else if (sum < target) {
            r++
        } else {
            l++
        };
    }
    return res;
};
```