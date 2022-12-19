### 解题思路
js

### 代码

```javascript
/**
 * @param {string} s
 * @param {number} k
 * @return {boolean}
 */
var canConstruct = function(s, k) {
    if(s.length < k) return false
    let hashMap = {}
    for (let i = 0; i < s.length; i++) {
        hashMap[s[i]] && (hashMap[s[i]]++)
        !hashMap[s[i]] && (hashMap[s[i]] = 1)
        
    }
    let ODD = 0
    Object.keys(hashMap).forEach(ele => {
        if (hashMap[ele] % 2 == 1) ODD++
    })
    if(ODD > k) return false
    return true

};
```