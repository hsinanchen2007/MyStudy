大部分人的解法,但indexof的时间复杂度应该是O(n),所以总的时间复杂度应该是O(n2)
```
var lengthOfLongestSubstring = function(s) {
  let num = 0,
    j = 0,
    t = 0,
    length = s.length;
  for (let i = 0; i < length; i++) {
    t = s.slice(j, i).indexOf(s[i]);
    if (t === -1) {
      num = Math.max(num, i - j + 1);
    } else {
      j = t + 1 + j;
    }
  }
  return num;
};
```
用map的解法,时间复杂度为O(n),执行时间有时能超过100%
```
var lengthOfLongestSubstring = function(s) {
  let num = 0,
    j = 0,
    length = s.length;
  const map = new Map();
  for (let i = 0; i < length; i++) {
    const char = s[i];
    if (map.get(char) !== undefined) {
      j = Math.max(map.get(char) + 1, j);
    }
    num = Math.max(num, i - j + 1);
    map.set(char, i);
  }
  return num;
};
```