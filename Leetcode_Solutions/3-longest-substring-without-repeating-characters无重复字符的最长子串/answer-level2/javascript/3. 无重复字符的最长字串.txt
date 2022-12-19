![image.png](https://pic.leetcode-cn.com/af30eb26ebb0e857d6cb80226c1e7ab9f53ea8c9ef75668855259207958fd333-image.png)

应该是最小的内存占用量吧。

```javascript
var lengthOfLongestSubstring = function(s) {
    let max = 0;
    let sub = '';
    for (let c of s) {
        const index = sub.indexOf(c);
        if (index !== -1) {
            const len = sub.length;
            if (len > max) {
                max = len;
            }
            sub = sub.slice(index + 1);
        }
        sub += c;
    }
    const len = sub.length;
    if (len > max) {
        max = len;
    }
    return max;
};
```