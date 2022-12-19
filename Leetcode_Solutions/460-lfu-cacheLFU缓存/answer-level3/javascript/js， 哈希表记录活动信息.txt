```
var LFUCache = function(capacity) {
    this.cache = new Map()
    this.capacity = capacity
    this.frequency = {} //记录每个项目的活动、使用次数信息
    this.activeId = 0 // 递增的id，用来计算项的最后活动时间
};

// 设置项的使用次数、活动时间
LFUCache.prototype.setFrequency = function(key) {
    this.activeId++ // 活动id自增，表示是最新的活动
    // 如果项已存在，则操作次数+1，活动id为最新的活动id
    if (this.frequency[key]) {
        this.frequency[key].time++ 
        this.frequency[key].activeId = this.activeId
    } else { // 不存在则初始化记录信息
        this.frequency[key] = {
            time: 0,
            activeId: this.activeId
        }
    }
}
/** 
 * @param {number} key
 * @return {number}
 */
LFUCache.prototype.get = function(key) {
    if (!this.cache.has(key)) return -1
    this.setFrequency(key)
    return this.cache.get(key)
};

/** 
 * @param {number} key 
 * @param {number} value
 * @return {void}
 */
LFUCache.prototype.put = function(key, value) {
    // 如果put操作，缓存要超过容量了，则需先删除“最近最少”使用的键先，这里要注意，如果键已存在无需删除，更新使用状态即可。
    if (this.cache.size + 1 > this.capacity && !this.cache.has(key)) {
        if (this.capacity <= 0) return // 如果容量不足直接退出函数

        let beRemovedKey = null // 记录需要被删除的key
        let minTime = Infinity // 记录所有项中的最小使用次数
        let recentActiveId = Infinity // 记录所有项中的最长时间没使用过的活动id

        // 遍历所有项，找出需要删除的key
        Object.keys(this.frequency).forEach(k => {
          const {time, activeId} = this.frequency[k]
          // 找出使用次数最小的项，如果项的使用次数相同，则找出最长时间没使用过的项
          if (time < minTime || (time === minTime && activeId < recentActiveId)) {
              minTime = time
              recentActiveId = activeId
              beRemovedKey = k
          }
        })

        delete this.frequency[beRemovedKey] // 删除使用记录
        this.cache.delete(parseInt(beRemovedKey)) // 删除该缓存
    }
    
    this.setFrequency(key)
    this.cache.set(key, value)
};
```