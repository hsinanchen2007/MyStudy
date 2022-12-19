使用1000个数组对应1000个桶，每一个桶也是数组。
contains：根据key值找到桶的索引，在该桶中查找元素即可。
add：先进行contains()判断，在进行添加操作，与contains操作类似。
remove：先使用contains()进行查找，再进行删除操作。
```javascript []
class MyHashSet {
  constructor () {
    this.buckets = [] // 存放若干个桶，默认为1000个
    for (let i = 0; i < 1000; i ++) { // 将每一个桶初始化为数组
      this.buckets.push([])
    }
    return this
  }

  add (key) {
    if (this.contains(key)) { // 值已经存在，插入失败
      return false
    } else {
      let index = key % 1000
      let bucket = this.buckets[index]
      bucket.push(key) // 在对应的桶中添加一个元素
      return true
    }
  }

  // 查找哈希表中是否含有该元素
  contains (key) {
    let index = key % 1000 // 哈希索引
    let bucket =  this.buckets[index]// 索引对应的桶
    for (let i = 0, len = bucket.length; i < len; i ++) { // 用indexOf其实更简单
      if (key === bucket[i]) { // 如果值在哈希表中，返回true
        return true
      }
    }
    return false // 值不在哈希表中，返回false
  }

  remove (key) {
    if (this.contains(key)) {
      let index = key % 1000
      let bucket = this.buckets[index]
      bucket.splice(bucket.indexOf(key), 1) // 删除key
      return true // 删除成功，返回true
    } else {
      return false
    }
  }
}

```