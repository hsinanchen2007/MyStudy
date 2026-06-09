
![javascript.jpg](https://pic.leetcode-cn.com/004f791f72d4c32ab2c13611f23aa41d6413a4b4ca38f71db0ff3f455b9b98af-javascript.jpg)

<br />

> es6新增两种数据结构, set和map, 其中set对应哈希集合, map对应哈希映射

<br />

- 明明提示`所有的值都在 [1, 1000000]的范围内`, 为什么我又碰到0了

```js
class MyHashMap {
  constructor () {
    this.data = {}
  }
  put(key, value) { // 向哈希映射中插入(键,值)的数值对。如果键对应的值已经存在，更新这个值。
    this.data[key] = value
  }
  get(key) { // 返回给定的键所对应的值，如果映射中不包含这个键，返回-1。
    return (this.data[key] || this.data[key] === 0) ? this.data[key] : -1
  }
  remove(key) { // 如果映射中存在这个键，删除这个数值对。
    delete this.data[key]
  }
}
```

