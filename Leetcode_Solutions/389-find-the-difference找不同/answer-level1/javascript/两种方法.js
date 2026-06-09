### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} s
 * @param {string} t
 * @return {character}
 */
var findTheDifference = function (s, t) {
    let arrT = []

    // 方案一 replace
    // for (let item of s) {
    //     t = t.replace(item, '')
    // }
    // return t


    // 方案二 ascii值
    let sum = 0
    for (let i = 0; i < t.length; i++) {
        sum += t.charCodeAt(i)
    }
    for (let i = 0; i < s.length; i++) {
        sum -= s.charCodeAt(i)
    }
    return String.fromCharCode(sum)
};
```