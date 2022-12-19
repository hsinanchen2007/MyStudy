看了几个 js 的版本感觉多多少少都有点问题，最后参考了下 [https://leetcode-cn.com/problems/lfu-cache/solution/java-13ms-shuang-100-shuang-xiang-lian-biao-duo-ji/](https://leetcode-cn.com/problems/lfu-cache/solution/java-13ms-shuang-100-shuang-xiang-lian-biao-duo-ji/) 的第二种自定义双链表解法，但是一直 a 不过，后来发现是在更新 freqMap 时忘记修改 minFreq 了，下面附上完整代码及相关注释。

```js
/**
 * 定义结点
 */
var Node = function (key, val) {
  this.key = key
  this.val = val
  this.freq = 1
  this.pre = null
  this.next = null
}

/**
 * 定义双向链表
 */
var DoubleLinkedList = function () {
  this.head = new Node() // 头结点
  this.tail = new Node() // 尾结点
  this.head.next = this.tail
  this.tail.pre = this.head
}

/**
 * 双向链表 删除结点
 * 先修改 next 再修改 pre
 */
DoubleLinkedList.prototype.remove = function (node) {
  node.pre.next = node.next
  node.next.pre = node.pre
}

/**
 * 双向链表 插入结点 4 步 操作 
 * 注意 操作顺序 先操作后面 再操作前面
 * 每一次插入 都操作 头结点的 next 即 频次相同 越靠近头结点表示是最近插入的
 */
DoubleLinkedList.prototype.add = function (node) {
  node.next = this.head.next
  this.head.next.pre = node
  this.head.next = node
  node.pre = this.head
}

/**
 * @param {number} capacity
 */
var LFUCache = function (capacity) {
  this.capacity = capacity // 总容量
  this.size = 0 // 已使用容量
  this.minFreq = 0 // 最小使用频率
  this.cacheMap = new Map() // key -- Node map
  this.freqMap = new Map() // freq -- DoubleLinkedList map
};

/** 
 * 取 对应 key 的 value
 * 记得 更新 freq
 * @param {number} key
 * @return {number}
 */
LFUCache.prototype.get = function (key) {
  // 判断 cacheMap 是否有 key
  if (!this.cacheMap.has(key)) {
    return -1
  }
  const node = this.cacheMap.get(key)
  // 更新 freqMap
  this.incFreq(node) 
  return node.val
};

/** 
 * 存 key value
 * @param {number} key 
 * @param {number} value
 * @return {void}
 */
LFUCache.prototype.put = function (key, value) {
  if (this.capacity === 0) {
    return 
  }
  // 先尝试 去 cacheMap 取节点 如果取得到 直接更新 节点的 val 并且 更新 freqMap
  const node = this.cacheMap.get(key)
  if (node) {
    node.val = value
    this.incFreq(node)
  } else {
    // 如果 没有 多余空间 需要删除
    if (this.capacity === this.size) {
      // 找到 freqMap 中 key 为 minFreq 的链表
      const minFreqLinkedList = this.freqMap.get(this.minFreq)
      // 删除 cacheMap 中的 key
      this.cacheMap.delete(minFreqLinkedList.tail.pre.key)
      // 删除 链表 尾结点的前一个结点 （因为每次新增的都在头结点 尾结点的是很久的）
      minFreqLinkedList.remove(minFreqLinkedList.tail.pre)
      this.size--
    }
    // 有多余空间 可以直接插入
    const newNode = new Node(key, value)
    this.cacheMap.set(key, newNode)
    // 更新 freqMap 先判断 是否有 key 为 1 的链表
    let doubleLinkedList = this.freqMap.get(1)
    if (!doubleLinkedList) {
      doubleLinkedList = new DoubleLinkedList()
      this.freqMap.set(1, doubleLinkedList)
    }
    // 将节点 插入到链表中
    doubleLinkedList.add(newNode)
    this.size++
    this.minFreq = 1
  }
};

/**
 * 更新 节点 freq
 */
LFUCache.prototype.incFreq = function (node) {
  // 先去 找到 freqMap 中对应 freq 的链表
  let freq = node.freq
  let doubleLinkedList = this.freqMap.get(freq)
  // 在链表中 删除 node 结点
  doubleLinkedList.remove(node)
  
  // 当时 漏掉了 这一步的判断
  // 当 freq 的频率 为 最小频率 且 对应 freqMap 的 链表为空
  if (freq === this.minFreq && doubleLinkedList.head.next === doubleLinkedList.tail) {
    this.minFreq = freq + 1
  }

  // 改变 自身节点的 freq
  node.freq++
  // 更新 freqMap 先判断 是否有 key 为 freq + 1 的链表
  doubleLinkedList = this.freqMap.get(freq + 1)
  if (!doubleLinkedList) {
    doubleLinkedList = new DoubleLinkedList()
    this.freqMap.set(freq + 1, doubleLinkedList)
  }
  doubleLinkedList.add(node)
}

/**
 * Your LFUCache object will be instantiated and called as such:
 * var obj = new LFUCache(capacity)
 * var param_1 = obj.get(key)
 * obj.put(key,value)
 */
```

希望对各位有所帮助~