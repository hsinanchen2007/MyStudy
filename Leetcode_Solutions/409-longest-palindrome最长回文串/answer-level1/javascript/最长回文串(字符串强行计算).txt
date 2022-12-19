```javascript
var longestPalindrome = function(s) {
  let len = s.length // 总长度
  let arrAll = [] // 可组成会文串数组
  let evenNumber = 0 // 偶数字符串数量
  let isHaveOdd = false // 是否存在奇数
  for (let i = 0; i < len; i++){
    let arr = []
    if (/[a-zA-z]/.test(s[i])) {
      s = s.replace(new RegExp(`${s[i]}`, 'g'), (val) => {
        arr.push(val)
        return '#'
      })
    }
    if (arr.length > 0) {
      arrAll.push(arr)
    }
  }

  arrAll.forEach(val => {
    if (val.length % 2 === 0) {
      evenNumber += val.length
    } else {
      isHaveOdd = true
      evenNumber += val.length - 1
    }
  })
  return maxOddNumber + evenNumber + Number(isHaveOdd)
};
```