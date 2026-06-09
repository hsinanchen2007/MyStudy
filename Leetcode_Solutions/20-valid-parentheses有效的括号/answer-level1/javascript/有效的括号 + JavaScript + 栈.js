执行用时76ms

思路:

创建一个空栈,创建`lookup`对象用于判断是否为一对合法的括号(这个方法是从评论区看的,之前是写的一个方法)

遍历字符串, 如果是左括号就入栈, 如果是右括号就弹出栈顶元素`top`, 然后用栈顶元素`top`与当前循环到的右括号(`s[i]`)比较, 如果是合法括号则继续循环, 循环完成后若栈为空返回`true`否则返回`false`, 如果不是合法括号则直接返回`false`, 

```
var isValid = function (s) {
  if (!s) return true
  if (s.length % 2 !== 0) return false
  let stack = []
  const lookup = {
    '{': '}',
    '[': ']',
    '(': ')'
  }
  for (let i = 0; i < s.length; i++) {
    if (s[i] === '(' || s[i] === '[' || s[i] === '{') {
      stack.push(s[i])
    } else {
      let top = stack.pop()
      if (!(lookup[top] === s[i])) {
        return false
      }
    }
  }
  return stack.length === 0
}
```

