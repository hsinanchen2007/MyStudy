### 解题思路

- 利用 ``哈希表`` 统计每个字母出现的次数
- 遍历一次 ``字符数组``，如果发现「它」只出现一次，直接返回对应的下标，否则循环终止之后返回 ``-1``

### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var firstUniqChar = function(s) {
    // 创建一个哈希表对象
    let map = new Map()
    // 统计次数
    for (let i = 0; i < s.length; i++) {
        let word = s.charAt(i)
        let val = map.get(word)
        if (map.has(word)) {
            map.set(word, val + 1)
        } else {
            map.set(word, 1)
        }
    }
    // 找到第一个只出现一次的字母
    for (let i = 0; i < s.length; i++) {
        if (map.get(s.charAt(i)) === 1) {
            return i
        }
    }
    return -1
};
```