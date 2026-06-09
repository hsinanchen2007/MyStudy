### 解题思路

**1. 每个字符串中都显示的全部字符**
**2. 包括重复字符**

如果没包括重复字符, 我们就可以直接拿第一个元素遍历, 判断 **其的每个字符** 在 **A的每个字符中** 是否出现过就行了.

但是, 题目要这么要求, 就增加的复杂性, 我们可以通过 

如果出现了一个字符符合条件, 我们就把他存到一个数组中,

**同时**, 把第一次出现的该字符从A中的每个字符串中删除
```
如:          list = []       A = ["cool","lock","cook"]  // 我们遍历的是'cool'这个字符串

第一次遍历得: list = ['c']     A = ["ool", "lok", "ook"]

第二次遍历得: list = ["c","o"]   A = ["ol", "lk", "ok"]
```

之后就都不符合第一个条件了

### 代码

```javascript
/**
 * @param {string[]} A
 * @return {string[]}
 */
var commonChars = function(A) {
  let list = []

  for(let prop of A[0]){
    let flag = A.every(item => {   // 第一个条件
      return item && item.indexOf(prop) > -1
    })

    if(flag){                     // 符合第一个条件进入
      list.push(prop)
      A = A.map(t => {            // 把存到数组list中的首次出现的字符 从 A 中删除
        let ind = t.indexOf(prop) // 如 cool , 字符'o' 只删除首个o, 得到 col
        let arr = t.split('')
        arr.splice(ind, 1)
        return arr.join('')
      })
    }
  }
  return list
};
```