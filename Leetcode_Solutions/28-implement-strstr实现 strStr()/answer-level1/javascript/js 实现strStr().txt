1. 首先进行特殊值的边界判断
2. 如果 needle 是空字符串，应返回0，同js的 indexOf 函数
3. 若 haystack 的长度小于 needle 的长度，则 haystack 一定不能匹配到 needle，返回 -1
4. 对 haystack 进行遍历，依次从 haystack 中取长度为 needle 字符长度的字符串，和 needle 进行比较，若相等则直接返回 index
5. 若遍历未匹配到，则在最后返回 -1
6. 性能很一般emmm，不晓得咋个优化了，先这样吧

```
/**
 * @param {string} haystack
 * @param {string} needle
 * @return {number}
 */
var strStr = function(haystack, needle) {
    const len1 = haystack.length
    const len2 = needle.length
    if (len2 === 0) return 0
    if (len2 > len1) return -1
    if (len1 === len2) return haystack === needle ? 0 : -1
    for(let i = 0; i < len1 - len2 + 1; i++) {
        let str = haystack.slice(i, len2 + i)
        if (str === needle) return i
    }
    return -1
};
```

![image.png](https://pic.leetcode-cn.com/5209e179ef0371aeaed8947b4b465442901bc874786e6cadedf68d5d956b62ea-image.png)

