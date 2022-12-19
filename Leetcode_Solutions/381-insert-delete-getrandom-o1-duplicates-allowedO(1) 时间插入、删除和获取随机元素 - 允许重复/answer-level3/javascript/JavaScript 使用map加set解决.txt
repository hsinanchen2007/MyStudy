### 解题思路
使用map加set解决，比较难实现的是删除的方法，详见注释

### 代码

```javascript
/**
 * Initialize your data structure here.
 */
var RandomizedCollection = function() {
    this.list = []
    // 使用map来同步list中每个值的索引，set,get都是O(1)操作
    this.map = new Map()
};

/**
 * Inserts a value to the collection. Returns true if the collection did not already contain the specified element. 
 * @param {number} val
 * @return {boolean}
 */
RandomizedCollection.prototype.insert = function(val) {
    this.list.push(val)
    if (!this.map.has(val)) {
        // 每个值使用一个set维护索引，add,delete都是O(1)操作
        const set = new Set()
        set.add(this.list.length - 1)
        this.map.set(val, set)
        return true
    } else {
        const set = this.map.get(val)
        set.add(this.list.length - 1)
        this.map.set(val, set)
        return false
    }
};

/**
 * Removes a value from the collection. Returns true if the collection contained the specified element. 
 * @param {number} val
 * @return {boolean}
 */
RandomizedCollection.prototype.remove = function(val) {
    if (this.list.length && this.map.has(val) && this.map.get(val).size) {
        const set = this.map.get(val)
        // 要移除的值存储在list中的index(多个任选一个)
        const arr = Array.from(set)
        const index1 = arr.pop()
        set.delete(index1)
        this.map.set(val, set)
        // 删除的不是list中最后一个值
        if (index1 < this.list.length - 1) {                    
            const lastVal = this.list[this.list.length - 1]
            // 更新set里的索引（把本来最后一个值移动到要删除值的位置）
            this.map.get(lastVal).delete(this.list.length - 1)
            this.map.get(lastVal).add(index1)
            // 这一步相当于，把要删除的值和list最后一个值交换
            this.list.splice(index1, 1, lastVal)
        }
        // 移除list中最后一个值
        this.list.pop()
        return true
    }
    return false
};

/**
 * Get a random element from the collection.
 * @return {number}
 */
RandomizedCollection.prototype.getRandom = function() {
    const index = Math.floor(Math.random() * this.list.length)
    return this.list[index]
};

/** 
 * Your RandomizedCollection object will be instantiated and called as such:
 * var obj = new RandomizedCollection()
 * var param_1 = obj.insert(val)
 * var param_2 = obj.remove(val)
 * var param_3 = obj.getRandom()
 */
```