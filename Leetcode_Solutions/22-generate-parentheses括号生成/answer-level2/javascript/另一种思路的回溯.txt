回溯就是递归的一种套路，
通用思路可以看剑指offer回溯章节或者liweiwei1419的题解，
核心逻辑是 1更新状态，2递归并更新参数状态，3把第一步更新的东西变回去；
在这里就是
`str += '('
 core(left + 1, right)
str = str.slice(0,-1)`
在最前面当然要写保存状态到容器里`result.push(str)`，
注意str要是引用类型需要浅拷贝一份副本，不然最后指向的同一份地址；这里是基本类型不需要拷贝了
再加上递归的终止`return`

也可以参照其他答案的回溯if条件

```
var generateParenthesis = function(n) {
  if (n === null || n === 0) {
    return []
  }
  
  let result = []
  let str = ''
  
  let core = function(left, right) {
    if (left + right >= 2 * n) {
      result.push(str)
      return
    }
    
    if (left < n && left === right) {
      // 只能填左括号，因为左右一样多,如'' '()' '(())' '()()'
      str += '('
      core(left + 1, right)
      str = str.slice(0,-1)
    } else if (left < n) {
      // 左右都可以填，只要满足左括号少于n
      str += '('
      core(left + 1, right)
      str = str.slice(0,-1)
      
      str += ')'
      core(left, right + 1)
      str = str.slice(0,-1)
    } else {
      // 左括号用完了，只剩下右括号可以用了
      str += ')'
      core(left, right + 1)
      str = str.slice(0,-1)
    }
  }
  
  core(0, 0)
  
  return result
};
```

方法二
动态规划加上广度搜索思路的暴力法
以一个括号组'()'为基础更新新的括号，按照每个间隔插入括号组
容器使用set集合省去去重
如果n=2则变为：左'()()' 中'(())' 右'()()' // 重复的不加入
再以'()()' '(())'为基础，重复至n组

```
var generateParenthesis = function(n) {
  if (n === 0) return []
  let result = new Set(['()'])

  for (let i=1; i<n; i++) {
    let temp = new Set()
    
    for (let s of result) {
      let len = i * 2 + 1
      for (let j=0; j<len; j++) {
        let str = s.slice(0, j) + '()' + s.slice(j)
        temp.add(str)
      }
    }
    
    result = temp
  }
  
  return [...result]
};
```