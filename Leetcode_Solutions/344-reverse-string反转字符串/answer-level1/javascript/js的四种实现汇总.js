
```
// 内置函数
var reverseString = function(s) {
  s.reverse()
}
```

```
// 单索引循环
var reverseString = function(s) {
  let len = s.length
  for (let i = 0; i < len / 2; i++) {
    ;[s[i], s[len - i - 1]] = [s[len - i - 1], s[i]]
  }
}
```

```
// 双指针
var reverseString = function(s) {
  let i = 0,
    j = s.length - 1
  while (i < j) {
    ;[s[i], s[j]] = [s[j], s[i]]
    i++
    j--
  }
}
```

```
// 递归
var reverseString = function(s) {
  let reverseSwap = function(s, i, j) {
    if (i >= j) return
    ;[s[i], s[j]] = [s[j], s[i]]
    reverseSwap(s, i + 1, j - 1)
  }

  reverseSwap(s, 0, s.length - 1)
}
```
