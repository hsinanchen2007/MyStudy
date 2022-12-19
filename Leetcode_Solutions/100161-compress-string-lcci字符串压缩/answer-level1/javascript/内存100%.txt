### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} S
 * @return {string}
 */
var compressString = function(S) {
    if(S.length == 0 || S.length==1) return S
    var len=S.length
    //var arr = S.split('')
    var str=''
    var count=1;
    //arr[S.length]=''
    for(var i=1;i<len;i++){
        
        if(S[i]==S[i-1]){
            count++;
        }else{
            str= str+ S[i-1]+ count;
            count=1;
        }
    }
    str += S[i-1] + count;
    //if(arr[len-1]==arr[len-2])
    if(str.length>=len){
        return S;
    }else{
        return str;
    }

};
```