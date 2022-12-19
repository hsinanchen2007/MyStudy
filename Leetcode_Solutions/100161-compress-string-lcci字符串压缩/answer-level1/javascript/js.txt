

### 代码

```javascript
/**
 * @param {string} S
 * @return {string}
 */
var compressString = function(S) {   
    if(!S){return S}
    let str = '';
    let count = 1;
    for(let i=0;i<S.length;i++){
        if(S[i] === S[i+1]){
            count ++
        }else{
            str += S[i] + count;
            count = 1
        }
    }
    return str.length<S.length?str:S

};
```