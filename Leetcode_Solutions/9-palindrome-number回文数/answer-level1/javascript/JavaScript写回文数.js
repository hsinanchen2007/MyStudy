```
var isPalindrome = function (x) {
  //先判断特殊情况
  //x = 0 为回文数
  if (x == 0) {
    return true
  }
  //x为负数或者x最后一位数为0,即不是回文数
  if (x < 0 || x % 10 == 0) {
    return false;
  }
  //x=121为例
  //反转整数,判断是否与x相等
  let y = 0;
  const temp = x; // temp = 121
  while (x != 0) {
    let rem = x % 10 // 1,2,1
    x = parseInt(x / 10) // 12,1,0
    y = y * 10 + rem //1,12,121
  };
  if (y == temp) {
    return true
  } else {
    return false
  }
};
```
