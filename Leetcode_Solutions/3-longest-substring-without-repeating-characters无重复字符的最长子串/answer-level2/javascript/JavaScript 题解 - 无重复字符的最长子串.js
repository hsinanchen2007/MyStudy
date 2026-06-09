思路：找到重复字符时从前一个重复字符处截断，在遍历中继续累加字符，同时更新长度；
```
var lengthOfLongestSubstring = function(s) {
  var l = 0, sub = '';

  for(c of s) {
    if (sub.indexOf(c) !== -1) {
      sub = sub.slice(sub.indexOf(c) +1);
    }

    sub += c;
    l = sub.length < l ? l : sub.length;
  }

  return l;
};
```

