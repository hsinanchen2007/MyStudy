
```javascript []
var numJewelsInStones = function(J, S) {
  var sum = 0;
  var jArr = J.split('');
  var sArr = S.split('');
  sArr.forEach(item => {
    var flag = jArr.find(j => j === item);
    if (flag) sum++;
  })
  return sum;
};
```

