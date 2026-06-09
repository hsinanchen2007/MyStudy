利用二分法

```
function isCommonPrefix(strs, len) {
  const str1 = strs[0].substring(0, len)

  for (let index = 1; index < strs.length; index++) {
    if (!strs[index].startsWith(str1)) {
      return false
    }
  }
  return true
}

var longestCommonPrefix = function(strs) {
  if (strs.length < 1 || strs === null) {
    return ''
  }
  
  let Min = Math.pow(2, 31)
  for (const item of strs) {
    Min = Math.min(item.length, Min)
  }

  let left = 1
  let right = Min

  while (left <= right) {
    const mid = (left + right) >>> 1

    if (isCommonPrefix(strs, mid)) {
      left = mid + 1
    } else {
      right = mid - 1
    }
  }
  return strs[0].substring(0, (left + right) >>> 1)
}
```
