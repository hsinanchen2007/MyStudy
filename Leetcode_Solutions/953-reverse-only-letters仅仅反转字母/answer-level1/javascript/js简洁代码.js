**1. 正则匹配选出英文字母
2. replace替换原字母**

**replace() 方法返回一个由替换值（replacement）替换一些或所有匹配的模式（pattern）后的新字符串。模式可以是一个字符串或者一个正则表达式，替换值可以是一个字符串或者一个每次匹配都要调用的回调函数。**

```javascript []
var reverseOnlyLetters = function(S) {
  var arr = S.match(/[a-zA-Z]/g)
  if (arr === null) return S
  return S.replace(/[a-zA-Z]/g, () => arr.pop())
}
```

