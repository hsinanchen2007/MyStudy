### 解题思路
此处撰写解题思路

### 代码
遇见不同的字母，将之前的字母和它出现的次数拼接。
```javascript
/**
 * @param {string} S
 * @return {string}
 */
var compressString = function(S) {
    var newStr = "";
    var j = 1;
    for(var i = 0;i<S.length;i++){
           if(S.charAt(i+1) !== S.charAt(i)){
               newStr += (S.charAt(i) + j);
               j = 1;
           }else {
               j++
           }
    }
    if(newStr.length >= S.length) {
        return S;
    }
    return newStr;
};
```