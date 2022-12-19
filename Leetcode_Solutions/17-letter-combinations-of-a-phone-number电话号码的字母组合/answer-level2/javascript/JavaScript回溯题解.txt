### 解题思路
回溯法遍历所有情况

### 代码

```javascript
/**
 * @param {string} digits
 * @return {string[]}
 */
var letterCombinations = function(digits) {
    if(!digits)return [];

    let map = ['','','abc','def','ghi','jkl','mno','pqrs','tuv','wxyz'];
    let result = [];
    var trackback = function(start,track){
        if(track.length===digits.length){
            result.push(track);
            return;
        }
        let str = map[digits[start]];
        for(let j=0;j<str.length;j++){
            trackback(start+1,track.concat(str[j]));
        }
    }   
    trackback(0,"");
    return result;    
};
```