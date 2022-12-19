```js
var findTheDifference = function(s, t) {
  // 取巧方法， 改变了原数据
  for(let item of s){
    t = t.replace(item, '')
  }
  return t
};
```