### 解题思路
將chars透過charCodeAt轉換成陣列表dictionary ex:a就放在dictionary[0]，接著跑迴圈取出word跟dictionary比對，
出現小於dictionary中字數的將字串長度相加即可

### 代码

```javascript
/**
 * @param {string[]} words
 * @param {string} chars
 * @return {number}
 */
var countCharacters = function(words, chars) {
    let dictionary=[];
    for(let i=0;i<chars.length;i++){
        let charN=chars.charCodeAt(i)-97;
        if(dictionary[charN]){
            dictionary[charN]++
        }else{
            dictionary[charN]=1;
        }
    }
    let res=0;
    for(let i=0;i<words.length;i++){
        for(let j=0;j<words[i].length;j++){
            let charN=words[i].charCodeAt(j)-97;
            if(!dictionary[charN]){
                break;
            }else {
                let charCount=dictionary[charN];
                let charLen=words[i].split('').filter((val)=>val==words[i][j]).length;
                if(charCount<charLen){
                    break;
                }
            }
            if(j==words[i].length-1){
                res+=words[i].length;
            }
        }
    }
    return res;
};
```