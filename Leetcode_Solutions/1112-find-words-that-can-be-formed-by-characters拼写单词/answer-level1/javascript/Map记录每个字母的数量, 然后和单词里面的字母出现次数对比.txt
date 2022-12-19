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
    const makeMap = str=> {
       return str.split('').reduce((map, e)=>{
            if(map[e])map[e]=map[e]+1;
            else {map[e]=1;}
            return map;
        }, {});
    }
    const charsMap = makeMap(chars);
    let c=0;
    for(let word of words){
        const wordMap = makeMap(word);
        let hasAll = true;
        for(let letter of word){
            //如果char的map里面没有这个字母，或者这个字母的数量比单词里面的这个字母的数量少，说明这个单词不够拼所以不要他
            if(!charsMap[letter] || wordMap[letter]>charsMap[letter]){
                hasAll = false;
                break;
            }
        }
        if(hasAll)c+=word.length;
    }
    return c;
};
```