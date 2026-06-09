一、正则计数， `/(\d)\1*/g` (反向引用)可以捕获相同数字。

```
var countAndSay = function(n) {
  if(n==1) return '1'
  function say(str){
    var reg = /(\d)\1*/g
    var result = ''
    var result_str = ''
    while(result = reg.exec(str)){
      result_str += result[0].length + result[1]
    }
    return result_str
  }  

  return say(countAndSay(n-1))
};
```
二、循环计数
```
var countAndSay = function (n) {
  if (n == 1) return '1'
  function say(str) {
    var result_str = '', i = 0; j = 0;
    while (j < str.length) {
      if (str[i] === str[j]) {
        j++
      } else {
        result_str += (j - i) + "" + str[i]
        i = j
      }
    }
    result_str += (j - i) + "" + str[i]
    return result_str
  }

  return say(countAndSay(n - 1))
};
```