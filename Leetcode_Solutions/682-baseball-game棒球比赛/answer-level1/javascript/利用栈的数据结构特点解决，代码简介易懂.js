### 解题思路
利用栈的数据结构特点解决，代码简介易懂

### 代码

```javascript
/**
 * @param {string[]} ops
 * @return {number}
 */
var calPoints = function(ops) {
   let result = 0

  if (ops.length === 0) return result

  class Stack {


    constructor () {
      this.data = []
    }

    add (value) {
      // 入
      return this.data.push(value)
    }

    remove () {
      // 出
      return this.data.pop()
    }

    getScore (key) {
      if (!isNaN(Number(key))) {
        this.add(Number(key))
      } else {
        const len = this.data.length
        switch (key) {
          case '+':
            let first = this.data[len - 1] || 0
            let second = this.data[len - 2] || 0
            this.add(first + second)
            break
          case 'D':
            this.add((this.data[len - 1] || 0) * 2)
            break
          case 'C':
            this.remove()
            break
        }
      }
    }

    getTotalScore () {
      return this.data.reduce((acc, v) => {
        return acc + v
      }, 0)
    }

  }

  // 声明一个新的栈

  const stack = new Stack()

  ops.forEach(v => {
    stack.getScore(v)
  })

  return stack.getTotalScore()  
};
```