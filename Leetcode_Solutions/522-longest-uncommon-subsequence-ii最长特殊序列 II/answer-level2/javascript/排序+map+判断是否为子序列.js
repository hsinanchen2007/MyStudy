这题是[521. 最长特殊序列 Ⅰ](https://leetcode-cn.com/problems/longest-uncommon-subsequence-i/)的升级版
1. 思想没有变=>***都是找出最长的字符串***
2. 如果*当前判断的字符串*不是数组中**最长**的，则需要查找其他字符串是否有此相对顺序（比当前判断的字符串长）
- *eg.['aabbcc', 'aabbcc', 'bcc', 'bc']*
- 判断'bcc'是要注意'aabbcc'有其字符的相对顺序，不是特殊序列
```javascript []
//判断是否满足相对顺序
var Traverse = function(item, str) {
  let j = 0
  for (let i = 0; i < str.length; i++) {
    if (str[i] === item[j]) j++
  }
  return j === item.length
}

var func = function(item, strs) {
  for (let i = 0; i < strs.length; i++) {
    if (item === strs[i] && i !== strs.length - 1) continue //跳过自己（除了自己为最后一项）
    if (item.length > strs[i].length) return item.length //判断的字符串大于strs剩余字符串长度，是=>找到最长特殊序列

    if (Traverse(item, strs[i]) && item !== strs[i]) {
      //是其他字符串的子序列，直接舍弃item
      break
    } else if (i === strs.length - 1) {
      //如果item在strs的最后一项，即全部遍历strs完成都没有重复
      return item.length
    }
  }
  return null
}

var findLUSlength = function(strs) {
  strs.sort((a, b) => b.length - a.length) //有利于简化，arr数组也是长字符串在前
  let hashmap = new Map()
  strs.forEach(v => {
    hashmap.set(v, hashmap.has(v) ? 1 + hashmap.get(v) : 1)
  })
  //存贮只出现一次的字符串
  //arr中长的字符串在前
  let arr = []
  hashmap.forEach((v, k) => {
    if (v === 1) {
      arr.push(k)
    }
  })

  for (let i = 0; i < arr.length; i++) {
    if (func(arr[i], strs)) {
      return arr[i].length
    }
  }

  return -1
}
```

![截屏2020-02-1720.07.19.png](https://pic.leetcode-cn.com/3b65fcfae460a5dc44ea7806c2c2da013dcc7b3f23818da55a251af50f6751df-%E6%88%AA%E5%B1%8F2020-02-1720.07.19.png)

