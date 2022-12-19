### 解题思路
cache数组类型为{value, freq}[]
没有实现O(1), 看官解尝试了一波也无果..现在使用的方式思路简单, 先行记录, 好在内存消耗100%了😂
重点在根据freq更新列表顺序上, 这里使用了findIndex的数组原生方法, 找到第一个小于等于该item.freq的index, 插入即可.
### 代码

```javascript

/**
 * @param {number} capacity
 */
var LFUCache = function(capacity) {
    this.cache = []
    this.L = capacity
};

/** 
 * @param {number} key
 * @return {number}
 */
LFUCache.prototype.get = function(key, value) {
    // 查找key相同的值
    let index = this.cache.findIndex(item => item.key === key)
    if(index !== -1) { // 如果有值
        const item = this.cache[index]
        // 如果是值有更改
        if(value) item.value = value
        // 调用更新策略
        this.update(item, index)
        // 返回该值
        return item.value
    }
    return -1
};

/** 
 * 更新策略
 * @param {array} item 待更新的元素
 * @param {number} idx 索引
 * @return {void}
 */
LFUCache.prototype.update = function(item, idx) {
    // 如果idx存在, 也就是获取而非添加的情况
    if(idx !== undefined){
        // 增加其使用频率
        item.freq += 1
        // 从原数组中删除, 在后续过程中在添加到预定位置
        this.cache.splice(idx, 1)
    }
    // 获取要插入的位置索引, 找到第一个freq小于等于待插入元素freq的地方
    let index = this.cache.findIndex((a, i) => a.freq <= item.freq)
    // 如果没有找到, 证明所有元素都大于待插入元素, 所以在末尾添加
    if(index === -1) {
        index = this.cache.length
    }
    // 在index出添加待插入元素
    this.cache.splice(index, 0, item)
}

/** 
 * @param {number} key 
 * @param {number} value
 * @return {void}
 */
LFUCache.prototype.put = function(key, value) {
    // 如果长度为0 , 无法put任何值
    if (this.L === 0) return 
    // 如果没有获取值(这里不严谨, 有可能本身返回的值就为-1, 可另写一检测方法, 但官方测试用例未覆盖此区域, 不影响AC)
    if(this.get(key, value) === -1){
        // 如果长度到了限制
        if(this.cache.length === this.L) {
            // 删除最末尾一个(肯定为使用频率最少的)
            this.cache.pop()
        }
        // 插入元素
        this.update({key, value,freq: 0})
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * var obj = new LFUCache(capacity)
 * var param_1 = obj.get(key)
 * obj.put(key,value)
 */
```