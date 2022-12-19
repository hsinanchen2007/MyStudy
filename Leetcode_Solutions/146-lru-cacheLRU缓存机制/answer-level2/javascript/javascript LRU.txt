```
/**
 * @param {number} capacity
 */
var LRUCache = function(capacity) {
  this.capacity = capacity
  this.cache = {}
  let linkNodeHead = {
    val: 0,
    key: null,
    next: null,
    before: null,
  }
  let linkNodeTail = {
    val: 0,
    key: null,
    next: null,
    before: null
  }
  linkNodeHead.next = linkNodeTail
  linkNodeTail.before = linkNodeHead
  this.linkNodeHead = linkNodeHead
  this.linkNodeTail = linkNodeTail
};

LRUCache.prototype.removeNode = function(key){
  this.cache[key].before.next = this.cache[key].next
  this.cache[key].next.before = this.cache[key].before
}

LRUCache.prototype.addToTail = function(node){
  this.linkNodeTail.before.next = node
  node.before = this.linkNodeTail.before
  node.next = this.linkNodeTail
  this.linkNodeTail.before = node
}

/** 
 * @param {number} key
 * @return {number}
 */
LRUCache.prototype.get = function(key) {
  if(this.cache[key] === undefined) return -1
  // remove node to tail, it's new record
  this.removeNode(key)
  this.addToTail(this.cache[key])
  return this.cache[key].val
};

/** 
 * @param {number} key 
 * @param {number} value
 * @return {void}
 */
LRUCache.prototype.put = function(key, value) {
  if(this.cache[key] !== undefined){
    this.cache[key].val = value
    this.removeNode(key)
    this.addToTail(this.cache[key])
    return
  }
  if(Object.keys(this.cache).length >= this.capacity){
    // cache overflow
    // delete linkNodes first one
    // add new cache to tail
    delete this.cache[this.linkNodeHead.next.key]
    this.linkNodeHead.next = this.linkNodeHead.next.next
    this.linkNodeHead.next.before = this.linkNodeHead
  }
  let newNode = {
    key: key,
    val: value,
    next: null,
    before: null,
  }
  this.addToTail(newNode)
  this.cache[key] = newNode
};

/** 
 * Your LRUCache object will be instantiated and called as such:
 * var obj = new LRUCache(capacity)
 * var param_1 = obj.get(key)
 * obj.put(key,value)
 */
```
