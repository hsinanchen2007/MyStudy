
### 双指针

```javascript
var reverseString = function(s) {
  let start = 0;
  let end = s.length - 1;
  while (start < end) {
    [s[start], s[end]] = [s[end], s[start]];
    start++;
    end--;
  }
  return s;
};
```

### 二分循环

执行用时 :124 ms， 在所有 JavaScript 提交中击败了95.34% 的用户
```JavaScript
var reverseString = function(s) {
  let len = s.length;
  let middle = Math.floor(len / 2);
  for (let i = 0; i < middle; i++) {
    let j = len - 1 - i;
    let temp = s[i];
    s[i] = s[j];
    s[j] = temp;
  }
  return s;
};
```

