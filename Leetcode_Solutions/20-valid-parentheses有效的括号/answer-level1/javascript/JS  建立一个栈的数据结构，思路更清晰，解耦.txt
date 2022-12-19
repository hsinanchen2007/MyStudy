先建立一个栈的数据结构，此类问题可以复用,思路同上
```
class Stack {
  constructor() {
    this.content = []
  }
  // 出栈，从栈顶也就是数组尾
  pop() {
    return this.content.pop()
  }
  // 入栈，从栈顶也就是数组尾
  push(item) {
    return this.content.push(item)
  }
  // 判断是栈空了没有
  isNull() {
    if (this.content.length == 0) {
      return true
    }
    return false
  }
  showLength() {
    return this.content.length
  }
  show() {
    console.log('当前栈的表示为', this.content)
  }
  // 检查是否闭合，如果是的话，返回true,允许出栈
  checkIsCLosed(item) {
    let end = this.content[this.content.length - 1]
    let obj = {
      ")": '(',
      "]": '[',
      "}": '{',
    }
    if (obj[item] == end) {
      return true
    } else {
      return false
    }
  }
}



var isValid = function (s) {
  if (s == '') {
    return true
  }
  let arr = s.split('')
  let open = '{[('
  let close = "}])"
  let len = arr.length
  if (close.indexOf(arr[0]) != -1 || len % 2 != 0) {
    return false
  }

  const test = new Stack()

  for (let i = 0; i < len; i++) {
    let current = arr[i]
    // 如果是开括号我们入栈
    if (open.indexOf(current) > -1) {
      test.push(current)
    } else if (close.indexOf(current) > -1 && test.checkIsCLosed(current)) {
      // 如果是闭括号且 能闭合 我们出栈
      test.pop(current)
    } else {
      //如果为比括号，同时不能闭合，那就是false
      return false
    }
  }
  return test.isNull() ? true : false
};
```
