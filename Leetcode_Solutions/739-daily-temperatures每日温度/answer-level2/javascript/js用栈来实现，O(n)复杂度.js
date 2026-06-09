```
Array.prototype.peek = function () {
  return this[this.length - 1]
}

var dailyTemperatures = function(T) {
  let result = new Array(T.length).fill(0)
  let stack = []
  for (let i = 0; i < T.length; i++) {
    while (stack.length && T[i] > T[stack.peek()]) {
      let index = stack.pop()
      result[index] = i - index
    }
    stack.push(i)
  }
  return result
}
```
