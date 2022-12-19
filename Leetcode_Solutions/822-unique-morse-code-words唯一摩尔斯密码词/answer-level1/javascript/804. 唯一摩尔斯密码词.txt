### 解题思路
set/map去重

### 代码

```javascript
/**
 * @param {string[]} words
 * @return {number}
 */
var uniqueMorseRepresentations = function(words) {
    const morse = [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]

    let _set = new Set()
    for(let i = 0; i < words.length; i++){
        let str = ''
        for(let j = 0; j < words[i].length; j++){
            str += morse[words[i].charCodeAt(j) - 97]
        }
        _set.add(str)
    }
    
    return _set.size
};
```