```
/**
 * @param {string} s
 * @return {string}
 * 寻找最大回文数扩展中心法
 */
var longestPalindrome = function (s) {
  if (s.length < 1) { return s; }
  var ss = s.split('');
  var start = 0;
  var end = 0;
  for (var i = 0; i < s.length; i++) {
    var len1 = expandCenter(ss, i, i);
    var len2 = expandCenter(ss, i, i + 1);
    var len = Math.max(len1, len2);
    if (len > end - start) {
      start = Math.ceil(i - (len - 1) / 2);
      end = Math.floor(i + len / 2);
    }
    console.log('len', len);
  }
  //因为slice是截止到end +1的前一位，就是会提取到end位置
  var result = ss.slice(start, end + 1).join('');
  return result;
}
var expandCenter = function (ss, L, R) {
  var left = L;
  var right = R;
  while (left >= 0 && right < ss.length && ss[left] === ss[right]) {
    left--;
    right++;
  }
  return right - left - 1;
}
```
