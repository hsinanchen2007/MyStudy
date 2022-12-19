### 解题思路
把两个字符串的单词 放到个数组里, 用对象记录单词出现的次数, 获取出现过一次的 属性 就行了

### 代码

```javascript
/**
 * @param {string} A
 * @param {string} B
 * @return {string[]}
 */
var uncommonFromSentences = function(A, B) {
  let list = A.split(' ').concat(B.split(' '))
  let obj = {}
  list.forEach(item => {
    obj[item] = obj[item] ? obj[item] + 1 : 1
  })
  let arr = []
  for(let prop in obj){
    if(obj[prop] === 1){
      arr.push(prop)
    }
  }
  return arr
};
```