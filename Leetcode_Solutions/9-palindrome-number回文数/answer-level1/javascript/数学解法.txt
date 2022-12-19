计算反转后的结果，然后进行比较

```javascript
var isPalindrome = function(x) {
  if (x < 0) return false;
  var m = x;
  var n = 0;
  while(m) {
      var last = m % 10;
      n = n * 10 + last;
      m = parseInt(m / 10);
  }
  
  return x === n;
};
``` 