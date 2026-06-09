![javascript.jpg](https://pic.leetcode-cn.com/22602be098eb3337a4a48296aec00bf41bc10662fa6300aa8993927cac052aea-javascript.jpg)

<br />

## 链表的结构

因为js没有内置的链表, 首先我们在leetcode中打印链表的数据结构, 看看到底长什么样子

```
// 假设链表为 5 -> 3 > 1

{
  val: 5,
  next: {
    val: 3,
    next: {
      val: 1,
      next: null
    }
  }
}

// 双链表的结构就会多一个prev, 这个就不写了, 不然字数限制
```

而且官方的描述也提到了: 单链表中的节点应该具有两个属性：`val` 和 `next`

- `val` 是当前节点的值
- `next` 是指向下一个节点的指针/引用

<br />

吐槽1: 但还是有人为了省事使用数组来设计链表, 不知你们的面试官看了心中是否毫无波澜

吐槽2: 官方提示都说了所有值都在 `[1, 1000]` 之内, 那些贡献测试用例的长点脑子行吗, 一批一批的往里面添加`0`算怎么肥事?

<br />

## 使用数组来设计 (不推荐, 偷懒写法)

> 大家可以很清晰的看到, 数组并不能体现出`val 是当前节点的值, next 是指向下一个节点的指针/引用`

```js
class MyLinkedList {
  constructor () {
    this.arr = []
  }
  get(index) {
    if (index < 0 || index >= this.arr.length) return -1
    return this.arr[index]
  }
  addAtHead(val) {
    this.arr.unshift(val)
  }
  addAtTail(val) {
    this.arr.push(val)
  }
  addAtIndex(index, val) {
    if (index < 0) { this.arr.push(val); return }
    if (index > this.arr.length) { return }
    this.arr.splice(index, 0, val)
  }
  deleteAtIndex(index) {
    if (index >= 0 && index < this.arr.length) this.arr.splice(index, 1)
  }
}
```

<br />

## 使用对象设计单链表

> 用对象来解题是真累啊, 这都要感谢那些测试用例里面包含`0`的**

```js
class MyLinkedList {
  constructor () {
    this.data = {}
  }
  get(index) {
    if (index < 0) return -1
    let curr = this.data
    for (let i = 0; i < index; i++) {
      if (!curr.next) return -1
      curr = curr.next
    }
    console.log(curr.val)
    return curr.val === undefined || curr.val === null ? -1 : curr.val
  }
  addAtHead(val) {
    if (this.data && !(this.data.val === undefined || this.data.val === null)) {
      this.data = { val, next: this.data }
    } else {
      this.data = { val, next: null }
    }
  }
  addAtTail(val) {
    let curr = this.data
    while (curr.next) {
      curr = curr.next
    }
    curr.next = { val, next: null }
  }
  addAtIndex(index, val) {
    if (index <= 0) return this.addAtHead(val)
    let curr = this.data
    for (let i = 0; i < index - 1; i++) {
      if (!curr || !curr.next) return null
      curr = curr.next
    }
    if (!curr.val && curr.val !== 0) return null
    curr.next = { val, next: curr.next }
  }
  deleteAtIndex(index) {
    if (index < 0) return null
    if (index === 0) return this.data = this.data.next
    let curr = this.data
    for (let i = 0; i < index - 1; i++) {
      if (!curr.next || !curr.next.next) return null
      curr = curr.next
    }
    console.log(JSON.stringify(curr))
    if (!curr.next) return null
    if (!curr.next.next) return curr.next = null
    curr.next = curr.next.next
  }
}
```

<br />

## 使用对象设计双链表

> 不就多一个prev来回嵌套吗

```js
class MyLinkedList {
  constructor () {
    this.data = null
  }
  get(index) {
    if (index < 0) return -1
    let curr = this.data
    while (index > 0 && curr) {
      curr = curr.next
      index--
    }
    return curr ? curr.val : -1
  }
  addAtHead(val) {
    this.data = {
      val, next: this.data, prev: null
    }
    if (this.data.next) this.data.next.prev = this.data
  }
  addAtTail(val) {
    if (this.data) {
      let curr = this.data
      while (curr.next) {
        curr = curr.next
      }
      curr.next = { val, next: null, prev: curr}
    } else {
      this.data = { val, next: null, prev: null }
    }
  }
  addAtIndex(index, val) {
    if (index <= 0) return this.addAtHead(val)
    let curr = this.data
    for (let i = 0; i < index - 1; i++) {
      if (!curr || !curr.next) return null
      curr = curr.next
    }
    if (!curr) return null
    let temp = curr.next
    curr.next = {
      val, prev: curr, next: curr.next
    }
    if (temp) temp.prev = curr.next
  }
  deleteAtIndex(index) {
    if (index < 0) return null
    let curr = this.data
    while (index > 0) {
      if (!curr) return null
      curr = curr.next
      index--
    }
    if (!curr) return null
    if (!curr.prev && !curr.next) {
      this.data = null
    } else if (!curr.prev) {
      curr.next.prev = curr.prev
      this.data = curr.next
    } else if (!curr.next) {
      curr.prev.next = null
    } else {
      curr.prev.next = curr.next
      curr.next.prev = curr.prev
    }
  }
}
```