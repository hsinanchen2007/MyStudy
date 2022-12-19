
1. 先把前序遍历的模板代码写出来，然后往里面加括号
2. 增加判断条件
- 如果是右子树为空的时候，那就不要加上括号
- 如果左子数为空，需要判断右子树是否为空，如果空的话就可以不要括号，如果不为空，那就需要加上括号


```javascript []
var tree2str = function(t) {
  if (!t) {
    return ''
  }
  var rightStr = ''
  if (t.right) {
    rightStr = `(${tree2str(t.right)})`
  }
  var leftStr = `(${tree2str(t.left)})`
  if (!t.right && leftStr === '()') {
    leftStr = ''
  }
  return `${t.val.toString()}${leftStr}${rightStr}`
};
```
