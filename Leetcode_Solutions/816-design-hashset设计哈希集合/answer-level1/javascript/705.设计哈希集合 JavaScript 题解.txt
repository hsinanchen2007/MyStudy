
![javascript.jpg](https://pic.leetcode-cn.com/da2d4a7a08ecd4043cd9300fadfd9797a7faa3c2e630276c676317f90a45fd16-javascript.jpg)

<br />

> es6新增两种数据结构, set和map, 其中set对应哈希集合, map对应哈希映射

## 使用数组设计哈希集合 (不建议)

- 比较耗费性能, 代码也没有对象设计来的简单

```js
class MyHashSet {
  constructor () {
    this.data = []
  }
  add(value) { // 向哈希集合中插入一个值。
    const data = this.data
    for (let i = 0; i < data.length; i++) {
      if (data[i] === value) return null
    }
    data[data.length] = value
  }
  contains(value)  { // 返回哈希集合中是否存在这个值。
    const data = this.data
    for (let i = 0; i < data.length; i++) {
      if (data[i] === value) return true
    }
    return false
  }
  remove(value) { // 将给定值从哈希集合中删除。如果哈希集合中没有这个值，什么也不做。
    const data = this.data
    for (let i = 0; i < data.length; i++) {
      if (data[i] === value) return data.splice(i, 1)
    }
  }
}
```

<br />

## 使用对象设计哈希集合 (建议)

```js
class MyHashSet {
  constructor () {
    this.data = {}
  }
  add(value) { // 向哈希集合中插入一个值。
    !this.data[value] && (this.data[value] = true)
  }
  contains(value)  { // 返回哈希集合中是否存在这个值。
    return !!this.data[value]
  }
  remove(value) { // 将给定值从哈希集合中删除。如果哈希集合中没有这个值，什么也不做。
    this.data[value] && (delete this.data[value])
  }
}
```
