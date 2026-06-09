### 解题思路
- 将每个单词反序建树
- 每次每个单词倒叙开始在树上匹配
- 如果匹配得全则继续下个单词
- 若匹配不全则判断需要增添几位字符串

#### 第一遍代码到最后AC遇到两个bug：
- bug-1：每次要记录已经匹配了多少个字符，后面更新总长度只要加上没被匹配的字符数就行了
- bug-2：并不是每次匹配到一半都能继续往后面接上：
  - 如果最后能在树上匹配到的字符有子节点的话，则需要将整串字符长度加入答案
  - 但是并没有在树的结构上体现（好像不太好表达清除就举例子吧）
  - 样例：['time','atime','btime']所对应的树结构仍然是：
  - [e]->[m]->[i]->[t]->[a,b]
  - 但答案字符串是：atime#btime#，与树结构不同

### 代码

```javascript
/**
 * @param {string[]} words
 * @return {number}
 */
var minimumLengthEncoding = function(words) {
  function tree(value, childern) { // 树结构
    this.value = value || ''       // 节点的值
    this.childern = childern || [] // 节点的所有子节点
  }
  let node = new tree()
  let count = 0
  for (let word of words) {
    let target = node
    let flag = false  // 记录当前单词的当前字符是否在书上被匹配到
    let found = false // 记录当前单词是否被完整匹配到
    let len = word.length
    word = word.split('').reverse()
    for (let i = 0; i<word.length;i++) {
      let c = word[i]
      for (let j of target.childern) {
        if (j.value === c) {
          flag = true
          target = j
          break
        }
      }
      if (flag) {
        len --                      // BUG-1：每次更新已经匹配了的字符数
        flag = false
        if (i === word.length -1) { // 发现当前单词已经完整被匹配
          found = true
        }
      } else {
        found = false
        if (target.childern.length > 0) {
          /* BUG-2:
           * 如果最后匹配得上的节点还有子节点的话
           * 则无法通过添加前缀的方式添加当前word
           * 而需要将整个长度加入答案
           */
          len = word.length
        }
        target.childern.push(new tree(c,[]))
        target = target.childern[target.childern.length - 1]
      }
    }
    if (!found) {
      count += len + (len<word.length?0:1)
    }
  }
  return count
};
```