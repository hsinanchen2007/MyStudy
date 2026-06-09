# 单层遍历

定义两个对象obj, objStr存储pattern和str的遍历结果
pattern 'aaaa' => '0000'
str 'dog cat cat dog' => '0110'

'0000'和'0110'第二个数字不一致直接返回false

时间复杂度O(n), 最差情况下要遍历一遍
空间复杂度O(n), 存储所有遍历的值

```
var wordPattern = function(pattern, str) {
  let obj = {}
  let objStr = {}
  let strArr = str.split(' ')
  let len = pattern.length
  if (strArr.length !== len) {
      return false
  }
  for (let i = 0; i < len; i++) {
      if (!obj.hasOwnProperty(pattern[i])) {
          obj[pattern[i]] = i
      }
      if (!objStr.hasOwnProperty(strArr[i])) {
          objStr[strArr[i]] = i
      }
      if (obj[pattern[i]] !== objStr[strArr[i]]) {
          return false
      }
  }
  return true
};
```
