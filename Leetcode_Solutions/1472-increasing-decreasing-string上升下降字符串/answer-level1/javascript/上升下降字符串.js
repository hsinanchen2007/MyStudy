### 解题思路
把字符串的字母转化为ASCII码存在对象模拟的哈希表里，使用Object.keys获取哈希表里的ASCII码从小到大排列的数组，最后正序逆序循环的向外输出字符。

### 代码

```javascript
/**
 * @param {string} s
 * @return {string}
 */
var sortString = function(s) {
    const o = {}
    for(let i = 0; i<s.length; i++) {
        const asciiCode = s[i].charCodeAt()
        if(o[asciiCode]) {
            o[asciiCode] = o[asciiCode] + 1
        } else {
            o[asciiCode] = 1
        }
    }
    const asciiKeys = Object.keys(o)
    let flag = true
    let i = 0
    let r = ""
    while(i < s.length) {
        if(flag) {
            for(let j = 0; j<asciiKeys.length; j++) {
                const code = asciiKeys[j]
                if(o[code]) {
                    o[code] = o[code] - 1
                    i++
                    r += String.fromCodePoint(code)
                }
            }
        } else {
            for(let j = asciiKeys.length - 1; j >= 0; j--){
                const code = asciiKeys[j]
                if(o[code]) {
                    o[code] = o[code] - 1
                    i++
                    r += String.fromCodePoint(code)
                }
            }
        }
        flag = !flag
    }
    return r
};
```