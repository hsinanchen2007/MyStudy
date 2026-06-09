### 解题思路
![image.png](https://pic.leetcode-cn.com/0e26360d1fd6426a7110fe9cd728d57ee21bb01a3e043be128d36e6f3595ed4c-image.png)

这个程序不是我写出来的，是我debug出来的。。。。。 ;-(
### 代码

```javascript
/**
 * @param {number} n
 * @param {number} m
 * @return {number}
 */
var lastRemaining = function(n, m) {
    if (m === 1) return n - 1;

    let arr = [],
        lastIdx = 0,
        nextIdx = -1,
        last = 0;

    for (let i = 0; i < n; i++) {
        if ((i + 1) % m === 0) {
            last = i;
            continue;
        }
        arr.push(i);
    }
    lastIdx = arr.indexOf(last + 1);
    if (last === 0) lastIdx = 0;
    if (lastIdx === -1) lastIdx = 0;

    while (arr.length != 1) {
        let len = arr.length;
        nextIdx = (lastIdx + m - 1) % len;
        lastIdx = nextIdx;
        arr.splice(nextIdx, 1);
    }
    return arr[0];
};
```