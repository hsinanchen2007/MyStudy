![image.png](https://pic.leetcode-cn.com/9939d6e9e6e1d70ba657f5824ece78b5345d059c105f5db6f57108ffbafbac3a-image.png)

1. 如果字符串需要重构为相邻字符都不相同，那么字符个数最多不能超过字符串长度的一半，满足这个条件即可重构，判断不可行比较简单

2. 重构字符串时，出现次数多的字符总是在外侧，因此我们用map存储字符及其出现次数，递归重构字符串，取map中出现次数最多且和字符串最后一个字符不同的字符添加上去，并更新map，当字符串长度等于原字符串长度时结束循环

```
/**
 * @param {string} S
 * @return {string}
 */
var reorganizeString = function(S) {
    let map = new Map()
    for(let i of S) {
        let value = map.get(i)
        if (value) {
            map.set(i, ++value)
        } else {
            map.set(i, 1)
        }
    }
    let len = S.length
    let max = Math.ceil(len/2)
    for(let [key, value] of map) {
        if (value > max) return ''
    }
    let fn = (str, map) => {
        let strLen = str.length
        if (len === strLen) return str
        let max = 0, maxStr = ''
        for(let [key, value] of map) {
            if (value > max && key !== str[strLen-1]) {
                max = value
                maxStr = key
            }
        }
        str += maxStr
        max--
        if (max === 0) {
            map.delete(maxStr)
        } else {
            map.set(maxStr, max)
        }
        return fn(str, map)
    }
    return fn('', map)
};
```

