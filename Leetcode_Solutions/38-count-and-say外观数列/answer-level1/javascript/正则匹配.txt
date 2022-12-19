```
var countAndSay = function(n) {
  let regExp = /(\d)\1*/g
  if(n === 1) return '1'
  return countAndSay(n-1).match(regExp).map(item => item.length+item[0]).join('')
};

```
