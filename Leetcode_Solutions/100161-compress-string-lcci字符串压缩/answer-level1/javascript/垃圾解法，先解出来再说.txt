### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} S
 * @return {string}
 */
var compressString = function(S) {
    let flag = 0, str ='';
    if(S.length === 0){
        return ""
    }
    for(let i =0 ; i<S.length;i++){  
        if(S[i] !== S[i+1]){
            str += `${S[i]}${i+1 -flag}`
            flag = i+1 
            if(i+1 >= S.length && str !== "" && str.length < S.length) {
            return str
            }
            else if(i+1 >= S.length && str !== "" && str.length >= S.length) {
               return S
            }
            
    }       
    }
};
```