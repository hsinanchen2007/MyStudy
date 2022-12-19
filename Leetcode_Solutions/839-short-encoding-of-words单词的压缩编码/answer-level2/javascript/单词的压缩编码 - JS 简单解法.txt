### 解题思路
暴力破解：
    1. 先根据单词长度排序（降序）
    2. 在根据indexOf判断，得到压缩后的S，返回S的长度

### 代码

```javascript
/**
 * @param {string[]} words
 * @return {number}
 */

/**
 * 暴力破解：
 *  1. 先根据单词长度排序（降序）
 *  2. 在根据indexOf判断，得到压缩后的S，返回S的长度
 */
var minimumLengthEncoding = function(words) {
    let S = ''
    words = words.sort( (a,b)=>b.length - a.length)
    for( let i = 0; i < words.length; i++ ){
        const word = words[i]
        const index = S.indexOf( word + '#' )
        if( !~index ) {
            S += `${word}#`
        }
    }
    return S.length
};
```