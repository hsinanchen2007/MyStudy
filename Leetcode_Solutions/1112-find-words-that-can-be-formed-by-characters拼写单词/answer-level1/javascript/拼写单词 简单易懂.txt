### 解题思路
遍历相加，注意： 每次遍历 chars 的每个字母都只能用一次。

### 代码

```javascript
/**
 * @param {string[]} words
 * @param {string} chars
 * @return {number}
 */
var countCharacters = function(words, chars) {
    let sum = 0
    for(let i=0 ; i<words.length; i++){
        const w = words[i]
        let s = chars, flag = true, j = 0
        while( j < w.length ){
            if( s.indexOf(w[j]) === -1 ){
                flag = false
                break
            }
            s = s.replace(w[j],'')
            j++
        }
        if( flag ) sum += w.length
    }
    return sum
};
```