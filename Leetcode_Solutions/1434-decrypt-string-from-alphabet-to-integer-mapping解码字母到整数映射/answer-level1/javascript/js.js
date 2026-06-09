### 
100%
100%
 s[i+2]==="#"

### 代码

```javascript
/**
 * @param {string} s
 * @return {string}
 */
var freqAlphabets = function(s) {
    var str = ""
    for(var i=0;i<s.length;){
        if(s[i+2]=='#'){
            let item = s.slice(i,i+2)
            str+=String.fromCharCode(Number(item)+96); 
            i+=3
        }else{
            let item = s[i]
            str+=String.fromCharCode(Number(item)+96); 
            i++
        }
    }
    return str
};
```