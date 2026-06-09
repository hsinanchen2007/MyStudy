
`大家好，我是 17
`
### 解题思路

1. 初始化的时候 先把第一个可删除 的元素 记录下来 ，this.num, 和可以删除 的次数 this.count
2. 执行next 的时候 先 执行 this.count-=n  看看当前元素够不够删除 ，够直接返回，不够就再循环删除下一个


### 代码

```javascript
/**
 * @param {number[]} A
 */
var RLEIterator = function (A) {
  this.data = A
  this.count = this.data.shift()||0
  this.num = this.data.shift()
};

/** 
 * @param {number} n
 * @return {number}
 */
RLEIterator.prototype.next = function (n) {
  this.count -= n

  while (this.count < 0 && this.data.length > 0) {
    this.count += this.data.shift()
    this.num = this.data.shift()
  }

  if (this.count < 0) {
    return -1
  }
  else {
    return this.num
  }
};

```