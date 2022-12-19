### 解题思路
递归

### 代码

```javascript
/**
 * @param {string} S
 * @return {string[]}
 */
var letterCasePermutation = function(S) {
    function traverse(S,index){
        if(index==0)  {
           return isLetter(S[index])
           ? [S[index].toUpperCase(), S[index].toLowerCase()] 
           : [S[index]]
        }
        if(index<S.length) {
            let next = traverse(S,index-1)
            if(isLetter(S[index])) {
               return [].concat(...next.map(v=> [(v+S[index].toUpperCase()),v+S[index].toLowerCase()]))
            }
            return [].concat(next.map(v => v+S[index]))
        }
    }
    return traverse(S,S.length-1)
};


function isLetter(letter) {
    let pattern =  new RegExp("[a-zA-Z]")
    return pattern.test(letter)
}
```