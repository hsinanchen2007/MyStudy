
`n % 26` 如果等于 0 的话, 那么这一位一定是 'Z', 记录这一位后 “翻页”, 也就是除以 27; 
对于其他情况, 用 `String.fromCharCode((n % 26) + 64)` 即可算出当前位的字母, 因为不用翻页, 所以除以 26 即可.

时间复杂度为 O(n), 空间复杂度为 O(1).

```
var convertToTitle = function(n) {
  let res = ''

  while (n > 0) {
    if (n % 26 !== 0) {
      res = String.fromCharCode((n % 26) + 64) + res
      n = (n / 26) | 0
    } else {
      res = 'Z' + res
      n = (n / 27) | 0
    }
  }

  return res
}
```
