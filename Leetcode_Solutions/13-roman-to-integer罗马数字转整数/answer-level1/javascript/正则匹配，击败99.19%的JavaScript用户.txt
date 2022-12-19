```js
var romanToInt = function(s) {
  var CONSTANT_OBJECT = {
    'I': 1,
    'V': 5,
    'X': 10,
    'L': 50,
    'C': 100,
    'D': 500,
    'M': 1000,
    'IV': 4,
    'IX': 9,
    'XL': 40,
    'XC': 90,
    'CD': 400,
    'CM': 900,
  };

  var number = 0;
  var temp = s.match(/IV|IX|XL|XC|CD|CM|[A-Z]/g);
  for(var i = 0; i < temp.length; i++) {
    number = number + CONSTANT_OBJECT[temp[i]];
  }
  return number;
};
```

核心在于用正则表达式匹配罗马数字，返回特定的字符串数组！