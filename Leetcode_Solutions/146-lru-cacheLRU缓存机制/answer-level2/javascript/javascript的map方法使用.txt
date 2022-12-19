### 使用对象：失败
本来直接使用对象编写的，利用可以获得对象的全部键值对，将值的活跃度按 最前面的是要被删除的，最后面的是最活跃的 排序，键值对按照对象的key排序，然而最后发现，新加入的key－value不是直接放到最后，而是按码值排序，因此会一直按‘0’'1''2'排序
```
var LRUCache = function(capacity) {
    this.cap = capacity;
    this.cache = {};
    this.length = 0;
};

/** 
 * @param {number} key
 * @return {number}
 */
LRUCache.prototype.get = function(key) {
    if(this.cache[key] != undefined) {
        var temp = this.cache[key];
        // 对象的键值会自动按照码值进行排序
        delete this.cache[key];
        console.log(this.cache); 
        this.cache[key] = temp;
        
        return temp;
    } else {
        return -1;
    } 
          
};

/** 
 * @param {number} key 
 * @param {number} value
 * @return {void}
 */
LRUCache.prototype.put = function(key, value) {
    if(this.length < this.cap && this.cache[key] == undefined) {
        this.cache[key] = value;
        this.length++;
    } else if(this.length == this.cap && this.cache[key] == undefined) {
        // Object.keys(object)可以获得对象的所有键值
        var arr = Object.keys(this.cache);
        delete this.cache[arr[0]];
        this.cache[key] = value;
    }
    console.log(this.cache);
};
```
### 使用Map对象
map和object有很大的相似之，但是map的键值对是有序的。
[object和map的比较](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Reference/Global_Objects/Map)
```
var LRUCache = function(capacity) {
    this.capacity = capacity;
    this.cache = new Map();
};

/** 
 * @param {number} key
 * @return {number}
 */
LRUCache.prototype.get = function(key) {
    if(this.cache.has(key)) {
        var val = this.cache.get(key);
        this.cache.delete(key);
        this.cache.set(key, val);
        return val;
    }
        
    else 
        return -1;
};

/** 
 * @param {number} key 
 * @param {number} value
 * @return {void}
 */
LRUCache.prototype.put = function(key, value) {
    if(this.cache.size < this.capacity && !this.cache.has(key)) {
        this.cache.set(key, value);
    } else if(this.cache.has(key)) {
        this.cache.delete(key);
        this.cache.set(key, value);
    } else if (this.cache.size = this.capacity) {
        // Map.prototype.keys() 返回一个迭代对象，而不是数组
        // 迭代对象 Iterator.next() 是迭代对象的第一个对象，而不是值，需要 .value获取值
        this.cache.delete(this.cache.keys().next().value);
        this.cache.set(key, value);
    }
};
```
### 参考大神的简单map代码
```
class LRUCache {
  constructor(capacity) {
    this.capacity = capacity
    this.map = new Map()
  }
 
  get(key) {
    let val = this.map.get(key)
    if (typeof val === 'undefined') { return -1 }
    this.map.delete(key)
    this.map.set(key, val)
    return val
  }
 
  put(key, value) {
    if (this.map.has(key)) { 
      this.map.delete(key) 
    }
 
    this.map.set(key, value)
    let keys = this.map.keys()
    while (this.map.size > this.capacity) { this.map.delete(keys.next().value) }
  }
}

```
