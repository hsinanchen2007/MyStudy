

```js

var lengthOfLongestSubstring = function (s) {
  let arr = [], max = 0;
  for (let i = 0; i < s.length; i++) {
    if (arr.includes(s[i])) {
      arr = arr.slice(arr.indexOf(s[i]) + 1)
    }
    arr.push(s[i])
    max = Math.max(max, arr.length)
  }
  return max
}






```