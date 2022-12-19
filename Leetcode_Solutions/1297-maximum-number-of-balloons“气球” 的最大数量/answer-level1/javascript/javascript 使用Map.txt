### 解题思路
使用map来找到单词中最少的字符

### 代码

```javascript
/**
 * @param {string} text
 * @return {number}
 */
var maxNumberOfBalloons = function(text) {
    const map = new Map()
    const set = new Set(['b', 'a', 'l', 'o', 'n'])
    const len = text.length
    let min = Infinity
    for (let i = 0; i < len; i++) {
        const str = text[i]
        set.has(str) && map.set(str, map.has(str) ? map.get(str) + 1 : 1)
    }
    // 如果缺少部分字母，直接返回
    if (map.size < 5) {
        return false
    }
    map.forEach((item, key) => {
        // 注意一个单词里有两个l和o
        if (key === 'l' || key === 'o') {
            item = Math.floor(item / 2)
        }
        min = Math.min(item, min)
    })
    return min
};
```