### 解题思路


### 代码

```javascript
/**
 * @param {string[]} words
 * @param {string} chars
 * @return {number}
 */
var countCharacters = function(words, chars) {
    let res = ""
    
    for(let i = 0;i<words.length;i++){
        let isInclude = true
        let onceChars = chars
        for(let j = 0;j<words[i].length;j++){
            if(onceChars.indexOf(words[i][j])==-1){
                isInclude = false
                continue
            }else{
               onceChars = onceChars.replace(words[i][j],"")
            }
        }
        if(isInclude){
            res+=words[i]
        }
    }
    return res.length
};
```