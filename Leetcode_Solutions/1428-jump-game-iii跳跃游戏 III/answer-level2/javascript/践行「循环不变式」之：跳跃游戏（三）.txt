循环不变式，即 loop invariant，是循环迭代能够正确解决问题的「关键所在」。

每一个使用循环迭代解决问题的程序，都有一个或显式或隐式的「loop invariant」。

循环迭代能解决问题的核心：保证每一次子循环中的「loop invariant」。

-----

时刻记住：**循环不变式虽然是求解问题的关键，但循环不变式本身并不等同于问题答案本身**。

稍加分析可知，跳跃游戏（三）是可以用深度或广度遍历解决的典型问题。

深度遍历关乎递归，此文略过不表。

着重拆解广度优先遍历中「循环不变式」相关的变量:
- 一个队列，头部和尾部需要正确维护，可以使用内置 ADT，JS 中没有，可用 array 模拟
- 一个集合，让已经入队的成员不再重复入队

在循环中确保「循环不变式」要做的事情：
- 正确维护队列的头尾
- 正确维护已入队成员集合

PS: 这里 `head++` 和 `++tail` 的使用，可谓是 `++` 运算符的典型示例了。

尽我所能的直白代码与注释：
```js
var canReach = function(arr, start) {
  // initialize queue by an arry
  let queue = Array(arr.length)
  // initialize done set
  let done = new Set()
  
  // initialize head and tail pointer of queue
  let head = tail = 0
  // invariant before loop:
  // invariant 1. set head and tail of queue
  queue[head] = start
  // invariant 2. add enqueued position into done set
  done.add(start)

  while (queue[head] != null) {
    // invariant during loop
    // invariant 1. dequeue the head firstly, then increase head pointer by one
    let i = queue[head++]

    // check whether it is target
    if (arr[i] === 0) {
      // termination 1: the dequeued one is the target and we can break loop
      return true
    }

    // enqueue new valid postion
    for (let j of [i + arr[i], i - arr[i]]) {
      if (j >= 0 && j < arr.length && !done.has(j)) {
        // invariant 2. increase tail pointer by one firstly, then enqueue one
        queue[++tail] = j
        // invariant 3. add enqueued position into done set
        done.add(j)
      }
    }
  }

  // termination 2: every position we can reach from the start is not the target
  // loop invariant after the normal loop: queue[head] == null && head == tail
  console.assert(arr[head] == null && head == tail, "something wrong")
  return false
};
```
