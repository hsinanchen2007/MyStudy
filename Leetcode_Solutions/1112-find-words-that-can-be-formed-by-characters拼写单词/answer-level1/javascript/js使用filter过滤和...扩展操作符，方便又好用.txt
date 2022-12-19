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
    let chs = chars.split("");
    let learned = words.filter( word => {
        let cs=[...chs];
        for(let i=0 ; i < word.length;i++){
            let j=cs.indexOf(word[i]);
            if(j===-1)return false;
            else{
                cs[j]="";
            }
        }
        return true;        
     });
     let sum=0;
     learned.forEach(v=>{
         sum += v.length;
     })
     return sum;

};
```