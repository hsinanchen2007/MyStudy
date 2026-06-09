不使用加号减号，可以使用位运算实现加减法
```
var getSum = function(a, b) {
  if (a === 0 || b === 0) {
    return a || b;
  }
  let temp;
  while (b != 0) {
    temp = a ^ b;
    b = (a & b) << 1;
    a = temp;
  }
  return a;
};
```
