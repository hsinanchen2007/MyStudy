### 解题思路
![image.png](https://pic.leetcode-cn.com/af5774ede712e8c2e4fb0a81e7bf30c1c3a8189d9981bafe195518f901634241-image.png)

读懂了才明白，就是判断奇数偶数。

### 代码

```javascript
/**
 * @param {string} seq
 * @return {number[]}
 */
var maxDepthAfterSplit = function(seq) {
    let ret = [],
        l = 1,
        r = 1;

    for (let i = 0; i < seq.length; i++) {
        if (seq[i] === "(") {
            if (l === 1) {
                ret.push(0);
            } else if (l === -1) {
                ret.push(1);
            }
            l *= -1;
        } else {
            if (r === 1) {
                ret.push(0);
            } else if (r === -1) {
                ret.push(1);
            }
            r *= -1;
        }
    }
    return ret;
};
```