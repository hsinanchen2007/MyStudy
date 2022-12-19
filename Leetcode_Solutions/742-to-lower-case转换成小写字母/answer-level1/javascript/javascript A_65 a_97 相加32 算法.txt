```
/**
 * @param {string} str
 * @return {string}
 */
var toLowerCase = function(str) {
  let ret = ''
  for(let i = 0; i < str.length; i++){
    let code = str.charCodeAt(i)
    if(code <= 90 && code>=65){
      ret += String.fromCharCode(code + 32)
    }else{
      ret += str[i]
    }
  }
  return ret
};


```

直接遍历字符串，A和a差32，所以对所有65～90之间的进行加32运算，最后拼接就行