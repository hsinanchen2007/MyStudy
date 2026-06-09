### 解题思路
此处撰写解题思路
扫描字符串，判断chars长度 - 剩余 chars字符串 是否等于 所扫描字符串的长度
### 代码

```javascript
/**
 * @param {string[]} words
 * @param {string} chars
 * @return {number}
 */
var countCharacters = function(words, chars) {
  let len = 0
    for(let i=0; i<words.length; i++){
        let str = chars 
        for(let k=0; k< words[i].length;k++){
            str = str.replace( str[str.indexOf(words[i][k])],"")
            if(chars.length - str.length === words[i].length){
            len += words[i].length
            }
        }


    } 
    return len
};
```