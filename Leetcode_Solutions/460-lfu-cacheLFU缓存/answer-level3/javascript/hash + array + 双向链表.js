
## hash + array + 双向链表
* hash存key和缓存的链表节点的引用
* 访问次数相同的缓存按时间顺序放在双向链表中，然后存放在索引次数为索引的array中
* 双向链表的节点信息有：缓存value，缓存key（方便删除缓存），缓存访问次数，前一个节点的引用，后一个节点的引用
* 双向链表每次将新节点插入到head，移除最近最少使用的则移除尾节点；


### 代码

```javascript
/**
 * @param {number} capacity
 */
var LFUCache = function (capacity) {
    this.map = new Map()
    this.freqArr = new Array()
    this.capacity = capacity
    this.minFreq = 1 // 方便找到访问次数最小的双向链表
    this.freqArr.push(new DoubleLink())
    this.freqArr.push(new DoubleLink())
};

/** 
 * @param {number} key
 * @return {number}
 */
LFUCache.prototype.get = function (key) {
    const node = this.map.get(key)
    if (node) {
        this._updateFreq(node)
        return node.value
    }
    return -1
};

/** 
 * @param {number} key 
 * @param {number} value
 * @return {void}
 */
LFUCache.prototype.put = function (key, value) {
    if (this.capacity <=0 ) return
    const node = this.map.get(key)
    if (node) {
        this._updateFreq(node)
        node.value = value
        return true
    }
    if (this.map.size >= this.capacity) {
        const lastNode = this.freqArr[this.minFreq].pop()
        this.map.delete(lastNode.key)
    }
    const newNode = new DoubleLinkNode(key, value)
    this.freqArr[1].unshift(newNode)
    this.minFreq = 1
    this.map.set(key, newNode)
};

LFUCache.prototype._updateFreq = function (node) {
    const freq = node.freq
    node.incFreq()
    this.freqArr[freq].del(node)
    const newFreq = freq + 1
    if (!this.freqArr[newFreq]) {
        this.freqArr[newFreq] = new DoubleLink()
    }
    this.freqArr[newFreq].unshift(node)
    // 最小访问次数等于freq，并且freq的双向链表为空，证明需要更新最小访问次数
    if (freq === this.minFreq && this.freqArr[freq].size === 0) {
        this.minFreq = newFreq
    }
}

var DoubleLinkNode = function (key, value) {
    this.key = key
    this.value = value
    this.freq = 1
    this.prev = null
    this.next = null
}
DoubleLinkNode.prototype.incFreq = function () {
    this.freq++
}

var DoubleLink = function () {
    this.head = new DoubleLinkNode(-1, -1)
    this.tail = new DoubleLinkNode(-1, -1)
    this.head.next = this.tail
    this.tail.prev = this.head
    this.size = 0
}
DoubleLink.prototype.unshift = function (node) {
    const tmp = this.head.next
    this.head.next = node
    node.next = tmp
    node.prev = this.head
    tmp.prev = node
    this.size++
}
DoubleLink.prototype.del = function (node) {
    const prev = node.prev
    const next = node.next
    prev.next = next
    next.prev = prev
    delete node.prev
    delete node.next
    this.size--
}
DoubleLink.prototype.pop = function () {
    const lastNode = this.tail.prev
    this.del(lastNode)
    return lastNode
}
```