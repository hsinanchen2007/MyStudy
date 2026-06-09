速度还行
从每个位置 例如1 2 3...位置插入新的'()'组合
'1(2)3' ---> '()()' '(())' '()()'
再去重 或者用set
重复n次
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
