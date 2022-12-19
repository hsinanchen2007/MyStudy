### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} S
 * @return {string}
 */
var removeOuterParentheses = function(S) {
    let sArr = [], sLen = 0, result = []
    for(let i = 0; i < S.length; i++){
        if(S[i] === '('){
            sLen++
        }else{
            sLen--
        }
        sArr.push(S[i])
        if(sLen === 0){
            sArr.shift()
            sArr.pop()
            result.push(sArr.join(''))
            sArr = []
        }
    }
    return result.join('')
};
```