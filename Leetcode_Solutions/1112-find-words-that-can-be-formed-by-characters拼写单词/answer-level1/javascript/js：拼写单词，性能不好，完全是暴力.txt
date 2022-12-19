### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string[]} words
 * @param {string} chars
 * @return {number}
 */
var countCharacters = function(words, chars) {
    let chars_count = {};
    let sum = 0;
    for(let i = 0; i < chars.length; i++){
        if(chars_count[chars[i]] === undefined){
            chars_count[chars[i]] = 1;
        }else{
            chars_count[chars[i]] += 1;
        }
    }
    for(let i = 0; i < words.length; i++){
        let words_count = {};
        for(let j = 0; j < words[i].length; j++){
            if(words_count[words[i][j]] === undefined){
                words_count[words[i][j]] = 1;
            }else{
                words_count[words[i][j]] += 1;
            }
        }
        let flag = 0;
        for(let z = 0; z < words[i].length; z++){
            if(words_count[words[i][z]] <= chars_count[words[i][z]]){
                flag = 1;
            }else{
                flag = 0;
                break;
            }
        }
        if(flag === 1){
            sum += words[i].length;
        }
    }
    return sum;
};
```