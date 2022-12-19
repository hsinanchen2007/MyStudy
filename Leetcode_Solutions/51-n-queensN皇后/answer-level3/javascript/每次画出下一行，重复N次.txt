暴力法
虽然速度很慢，比较好理解
写个题解纪念一下

```
var solveNQueens = function(n) {
  let result = []

  let line0 = []
  for (let i=0; i<n; i++) {
    let eachLine = ['.'.repeat(i) + 'Q' + '.'.repeat(n-i-1)]
    line0.push(eachLine)
  }
  
  let helper = function() {
    let temp = []
    for (let i=0; i<result.length; i++) {
      let nextLine = renderNextLine(result[i])
      temp = [...temp, ...nextLine]
    }
    result = temp
  }
  
  let renderNextLine = function(list) {
    let temp = []
    let eachLine = Object.assign([], line0)
    for (let i=0; i<eachLine.length; i++) {
      if (judge(eachLine[i][0], list)) {
        temp.push(list.concat(eachLine[i][0]))
      }
    }
    return temp
  }
  
  let judge = function(str, oldList) {
    let temp = true
    let len = oldList.length
    let now = [len, str.indexOf('Q')]
    for (let i=0; i<len; i++) {
      let old = [i, oldList[i].indexOf('Q')]
      if (
           (now[1] === old[1])
        || (now[0] - old[0] === now[1] - old[1])
        || (now[0] - old[0] === old[1] - now[1])
      ) {
        temp = false
        break
      }
    }
    return temp
  }
  
  // 生成第一行
  result = Object.assign([], line0)
  // 生成剩余行
  for (let i=1; i<n; i++) {
    helper()
  }
    
  return result
};
```
