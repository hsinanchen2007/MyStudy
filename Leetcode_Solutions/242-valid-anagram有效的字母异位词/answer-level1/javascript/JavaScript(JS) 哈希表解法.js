### 解题思路
遍历 s 建立哈希表，遍历 t 核验即可

### 代码

```javascript
/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isAnagram = function (s, t) {
    if (s.length != t.length) return false
    let len = s.length, hashMap = new Map();
    // 统计字符串 s 中的字母个数
    for (let i = 0; i < len; i++) {
        if (hashMap.has(s[i])) {
            hashMap.set(s[i], hashMap.get(s[i]) + 1);
        } else {
            hashMap.set(s[i], 1);
        }
    }
    // 通过 hashMap 核验字符串 t
    for (let i = 0; i < len; i++) {
        if (hashMap.has(t[i])) {
            hashMap.set(t[i], hashMap.get(t[i]) - 1);
            !hashMap.get(t[i]) && hashMap.delete(t[i]);
        } else {
            return false
        }
    }
    return true
};
```