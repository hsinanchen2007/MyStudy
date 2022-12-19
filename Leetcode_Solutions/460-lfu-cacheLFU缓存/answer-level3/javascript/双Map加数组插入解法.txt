
第一个Map存储 key-value值

第二个Map存储 key对应的频率

数组存储 key值


```javascript []
/**
 * @param {number} capacity
 */
var LFUCache = function (capacity) {
    this.cache = new Map(); //key-value值
    this.freqMap = new Map(); //频率
    this.queue = []; //储存key数组
    this.size = 0; // 长度
    this.capacity = capacity; //深度
};
LFUCache.prototype.updata = function (key) {
    // 插入算法
    let that = this;
    let idx = this.queue.findIndex((item) => item == key); //获取key在数组位置
    let item = this.queue[idx];
    this.queue.splice(idx, 1); //去掉此时key
    let index = this.queue.findIndex((key) => {
        return that.freqMap.get(key) > that.freqMap.get(item); //返回key应该插入位置
    });
    if (index == -1) {
        this.queue.push(item); //没找到合适位置，key插在最后面
    } else {
        this.queue.splice(index, 0, item); // 找到位置插到合适位置
    }
};
/**
 * @param {number} key
 * @return {number}
 */
LFUCache.prototype.get = function (key) {
    if (this.cache.has(key)) {
        //哈希key
        let val = this.freqMap.get(key) + 1; //频率加一
        this.freqMap.set(key, val); //更新频率
        this.updata(key); //重新插入key
        return this.cache.get(key);
    } else {
        return -1;
    }
};

/**
 * @param {number} key
 * @param {number} value
 * @return {void}
 */
LFUCache.prototype.put = function (key, value) {
    if (this.capacity == 0) {
        //深度为0
        return;
    }
    if (this.cache.has(key)) {
        //有key值时候
        let val = this.freqMap.get(key) + 1; //频率加一
        this.cache.set(key, value); //更新key值
        this.freqMap.set(key, val); //更新频率
        this.updata(key); //重新插入key
    } else {
        if (this.size === this.capacity) {
            //深度不够
            let temp = this.queue.shift(); //删除数组第一元素
            this.cache.delete(temp); //删除key
            this.freqMap.delete(temp); //删除频率
            this.size--; //长度减一
        }
        this.cache.set(key, value); //添加key值
        this.freqMap.set(key, 0); //添加频率
        this.queue.push(key); //数组添加key
        this.updata(key); //重新插入key
        this.size++; //长度加一
    }
};
/**
 * Your LFUCache object will be instantiated and called as such:
 * var obj = new LFUCache(capacity)
 * var param_1 = obj.get(key)
 * obj.put(key,value)
 */
```