### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} s1
 * @param {string} s2
 * @return {boolean}
 */
var checkInclusion = function(s1, s2) {
    if (s1.length > s2.length) {
        return false;
    }
    let base = 'a'.charCodeAt(0);
    const toMap = (str) => {
        let map = [];
        for (let i=0; i<26; i++) {
            map[i] = 0;
        }
        for (let i=0; i < str.length; i++) {
          let code = str.charCodeAt(i) - base;
          map[code]++;
        }
        return map;
    }
    let s1Len = s1.length;
    let s1Map = toMap(s1); 
    let s2SubMap = toMap(s2.slice(0, s1Len));
    let sameCount = 0;
    for (let i=0; i<26; i++) {
        if (s1Map[i] === s2SubMap[i]) {
            sameCount++;
        }
    }
    if (sameCount === 26) {
        return true;
    }
    for (let i=0; i< s2.length - s1Len; i++) {
        let removeCode = s2.charCodeAt(i) - base;
        let addCode = s2.charCodeAt(i + s1Len) - base;
        if (s1Map[removeCode] === s2SubMap[removeCode]) {
            sameCount--;
        }
        s2SubMap[removeCode]--;
        if (s1Map[removeCode] === s2SubMap[removeCode]) {
            sameCount++;
        }
        if (s1Map[addCode] === s2SubMap[addCode]) {
            sameCount--;
        }
        s2SubMap[addCode]++;
        if (s1Map[addCode] === s2SubMap[addCode]) {
            sameCount++;
        }
        if (sameCount === 26) {
            return true;
        }
    }
    return false;
};


```