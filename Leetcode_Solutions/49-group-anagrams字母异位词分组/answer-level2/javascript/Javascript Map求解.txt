### 解题思路
使用map存储异位词

### 代码

```javascript
/**
 * @param {string[]} strs
 * @return {string[][]}
 */
var groupAnagrams = function(strs) {
    const len = strs.length
    const res = []
    const map = new Map()
    for (let i = 0; i < len; i++) {
        const str = strs[i].split('').sort().join('')
        if (!map.has(str)) {
            const arr = []
            arr.push(strs[i])
            map.set(str, arr)
        } else {
            const arr = map.get(str)
            arr.push(strs[i])
            map.set(str, arr)
        }
    }
    map.forEach(value => {
        res.push(value)
    })
    return res
};
```