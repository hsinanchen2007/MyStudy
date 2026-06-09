- 纯属娱乐 
- 时间复杂度很差
- \1 反向引用   表示之前一个捕获组 然后重复 k-1次就可以了
- 再附带一个常规解法
```
var removeDuplicates = function (s, k) {
  let reg = new RegExp('([a-z])\\1{' + (k - 1) + '}', 'g');
  while (reg.test(s)) {
    s = s.replace(reg, '');
  }
  return s;
};

var removeDuplicates = function (s, k) {
  let stack = [];
  let len = 0; // 表示栈中最后进入的字母的重复次数
  for (let char of s) {
    if (char !== stack[stack.length - 1]) {
      len = 1;
      stack.push(char);
    } else if (len === k - 1) {
      stack.splice(stack.length - k + 1);
      if (stack.length > 0) {
        len = 1;
        let length = stack.length - 1;
        while (stack[length - 1] === stack[length]) {
          ++len;
          --length;
        }
      } else {
        len = 0;
      }
    } else {
      ++len;
      stack.push(char);
    }
  }
  return stack.join('');
};
```

