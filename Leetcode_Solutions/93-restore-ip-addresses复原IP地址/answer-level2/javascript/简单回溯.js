```
var restoreIpAddresses = function (s) {
  if (s.length > 12) return []
  let result = []
  fn(s, [], result)
  return result
};
```


**递归遍历**
- 递归结束条件：当判断到最后一段时，如果合法直接加入到结果集
- 递归体：每一段长度可以为1、2、3，所以每次都有三种可能
```
function fn(remain, temp, result) {
  if (temp.length === 3) {
    regular(remain) && result.push([...temp, remain].join('.'))
    return
  }
  for (let i = 1; i < 4; i++) {
    regular(remain.substr(0, i)) && fn(remain.substr(i), [...temp, remain.substr(0, i)], result)
  }
}
```

**是否合法需要满足以下条件：**
- 大于等于0； 
- 小于等于255 
- 如果是一位可以为0，如果超过一位，不能以0开头
```
/**
 * @desc 用来判断每一段是否合法
 * @param {string} s
 * @return {boolean}
 */
function regular(s) {
  if (!s.length) return false
  return 0 <= +s && +s <= 255 && (s.length > 1 ? !!+s[0] : true)
}
```