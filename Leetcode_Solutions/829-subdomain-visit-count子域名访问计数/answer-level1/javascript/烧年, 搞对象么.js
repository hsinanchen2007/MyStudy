### 解题思路

要过年了, 得搞搞对象了~

题目的意思就是要 分类统计 , 它给一个字符串数组, 有数字 有字符窜. 它要统计 原字符串及每个小点后部分的次数, 统计就是相加

既然它敢给数组我, 那也无需不客气, 遍历伺候, 顺便new 个对象.

把 字符串 分隔开来  数组归数字 字符串归字符串 , 拿字符串当对象属性, 数字当值

当他还有小点的时候, 截取第一个小点之后的字符, 继续往对象添加属性, 直到没有小点了

之后, 一个对象到手, 嘿嘿

最后, 把对象遍历, 按题目要求 格式为访问次数+空格+地址 整成一个数组

搞电收工.

### 代码

```javascript
/**
 * @param {string[]} cpdomains
 * @return {string[]}
 */
var subdomainVisits = function(cpdomains) {
  let obj = {}
  cpdomains.forEach(item => {
    let str = item.split(' ')
    let prop = str[1]
    let num = +str[0]

    obj[prop] = obj[prop] ? obj[prop] + num : num
    while (prop.indexOf('.') > -1) {
      prop = prop.substr(prop.indexOf('.')+1)
      obj[prop] = obj[prop] ? obj[prop] + num : num
    }
  })
  let list = []
  for(let prop in obj) {
    let str = obj[prop] + ' ' + prop
    list.push(str)
  }
  return list
}
```