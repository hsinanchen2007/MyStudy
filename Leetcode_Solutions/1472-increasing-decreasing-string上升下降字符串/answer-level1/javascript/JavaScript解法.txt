二话不说，先上代码
```js
var sortString = function(s) {
  s = s.split('').map(v => v.codePointAt())
  var res = []
  while(s.length) {
    let min = -Infinity
    let max = Infinity
    while(true) {
      min = Math.min(...s.filter(v => v > min))
      if(min === Infinity) {
        break;
      }
      res.push(min)
      s.splice(s.indexOf(min), 1)
    }
    while(true) {
      max = Math.max(...s.filter(v => v < max))
      if(max === -Infinity) {
        break;
      }
      res.push(max)
      s.splice(s.indexOf(max), 1)
    }
  }
  return res.map(v => String.fromCharCode(v)).join('')
};
```
这应该是最最直观的解法，说下思路。题目比的是字母大小，其实就是比较字母的ASCLL码的大小，这里为了方便操作，我们直接把这个字符串分解成数组并且转换成对应的ASCLL码，然后按照题目进行while循环，大循环里面嵌套两个小循环，分别是找最小和找最大，只要找到一个就把这个从总的数组里剔除掉，拼接在结果数组里面，直到总的数组空，退出循环，把结果数组还原成字母字符串，返回它。