**解题思路就是利用两个指针对碰的方法**

```
const isPalindrome = (x) => {
  if (x < 0) {
    return false
  }
  const str = x.toString()
  let i = 0
  let j = str.length - 1
  let flag = true
  while (i < j) {
    if (str[i] !== str[j]) {
      flag = false
      break
    }
    i++
    j--
  }
  return flag
}
```

