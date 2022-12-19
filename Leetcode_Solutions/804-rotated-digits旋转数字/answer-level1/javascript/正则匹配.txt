总共有两个判断条件：
+ 3、4、7旋转后会失效，所以不能存在其中这三个数。
+ 2、5、6、9旋转后才会改变值，如果一个能够旋转的数没有这四个数其中之一，说明旋转后和原数相同，也不符合题意。
```
var rotatedDigits = function(N) {
  let ans = 0;
  let reg1 = new RegExp("3|4|7");
  let reg2 = new RegExp("2|5|6|9");
  for(let i=1; i<=N; i++) {
    if(!reg1.test(i) && reg2.test(i)) {
      ans++;
    }
  }
  return ans;
};
```