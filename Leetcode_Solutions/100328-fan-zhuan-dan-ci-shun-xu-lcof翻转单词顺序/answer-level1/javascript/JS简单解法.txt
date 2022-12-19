### 解题思路
先将字符串转化为数组，然后将所有空格去除，再反转并用空格隔开后转化为字符串

### 代码

```javascript
let reverseWords = (s) => {
  let arr = s.split(' ').filter( item => {
    if (item !== ' ') return item
  })
  return arr.reverse().join(' ')
}

```