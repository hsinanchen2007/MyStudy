### 解题思路

每日一题变得好繁琐。。没有看题解就开始照着自己的想法写，写得心累。。大概思路和官方二解好像是差不多的（没仔细看）

因为看了下题解并不是很多，所以就发出来提供一下大概思路，可以参考参考。

- 用两个Map进行存储
    - 一个是以`key`为键值，保存`具有value、freq属性的对象`的cacheMap
    - 一个是以`freq`为键值，保存`保存了属于该freq的所有key值的链表`的freqMap
- get时
    - 查cacheMap可得value，然后更新freqMap里记录的freq，再更新cacheMap里记录的freq
- put时
    - 先检查容量是否为0，为0则不put
    - 检查是否是已put的值，有的话则刷新value，并且freq++（这一种情况，题目并没有解释，无奈）
    - 如果是没有put过的值，则检查容量是否满了
        - 没满，则加入cacheMap，然后在freqMap里freq为1的链表的尾节点后再加上存储该key的节点
        - 满了，需要先删掉最不活跃的（即freqMap里键值排最前的链表中的第一个key），再执行上面的操作

> 想的时候觉得大概思路还是挺简单的，但是实现起来感觉有点繁琐，于是代码也写得稀烂 Orz 懒得改了呜呜

### 代码

```javascript
/**
 * @param {number} capacity
 */
var LFUCache = function(capacity) {
    this.capacity = 0;
    this.maxCapacity = capacity;
    this.cacheMap = {};
    this.freqMap = {};
};

/** 
 * @param {number} key
 * @return {number}
 */
LFUCache.prototype.get = function(key) {
    const targetCache = this.cacheMap[key];
    // 是否命中缓存
    if (targetCache) {
        // 增加freqMap里的freq记录
        this.update(key);
        // 增加cacheMap里的freq记录
        targetCache.freq++;
        // 返回get结果
        return targetCache.value;
    } else {
        return -1;
    }
};

/** 
 * @param {number} key 
 * @param {number} value
 * @return {void}
 */
LFUCache.prototype.put = function(key, value) {
    if (this.maxCapacity === 0) return;
    if (!this.cacheMap[key]) {
        if (this.capacity === this.maxCapacity) {
            // 缓冲区满了，清除
            this.clean();
        }
        // 没有该key记录，则增加缓存记录
        this.cacheMap[key] = {
            value: value,
            freq: 1
        };
        // 将缓存记录到freqMap上
        if (!this.freqMap[1]) {
            this.freqMap[1] = new LinkedList();
        }
        this.freqMap[1].append(key);
        this.capacity++;
    } else {
        // 有该记录，则覆盖value值，且访问次数++
        this.update(key);
        this.cacheMap[key].value = value;
        this.cacheMap[key].freq++;
    }
};

/**
 * 增加freqMap里所记录的访问次数
 * @param {number} key
 */
LFUCache.prototype.update = function(key) {
    let targetFreq = this.cacheMap[key].freq;
    // 删除旧频率记录
    if (this.freqMap[targetFreq].delete(key) === -1) {
        // 删除后，该频率下无其他缓存，则释放该频率所记录的空间
        delete this.freqMap[targetFreq];
    }
    // 频率++
    targetFreq++;
    // 记录到新的频率记录去
    if (!this.freqMap[targetFreq]) {
        this.freqMap[targetFreq] = new LinkedList();
    }
    this.freqMap[targetFreq].append(key);
}

/**
 * 去除最不常访问的缓存
 * @param {number} key
 */
LFUCache.prototype.clean = function(key) {
    // 找到频率最低的元素
    const min = this.freqMap[Object.keys(this.freqMap)[0]];
    // 删除该元素的缓存
    delete this.cacheMap[min.head.next.value];
    // 删除该元素在freqMap里的记录
    if(min.unshift() === -1) {
        // freqMap该频率下无其他记录，则释放该频率记录的空间
        delete this.freqMap[Object.keys(this.freqMap)[0]];
    }
    this.capacity--;
}

/**
 * 自定义链表节点
 * @param {number} value
 */
var Node = function(value = NaN) {
    // 这里的value，用来保存key值
    this.value = value;
    this.next = null;
}

/**
 * 自定义链表
 */
var LinkedList = function() {
    this.head = new Node();
    this.end = this.head;
}

/**
 * 在链表尾节点后插入节点
 * @param {number} value
 */
LinkedList.prototype.append = function(value) {
    this.end.next = new Node(value);
    this.end = this.end.next;
}

/**
 * 在链表中删除目标节点
 * @param {number} value
 * @return {number} -1:链表为空 0:未找到删除目标 1:删除成功
 */
LinkedList.prototype.delete = function(value) {
    let last = this.head;
    let node = this.head.next;
    // 找目标节点
    while (node && node.value !== value) {
        last = last.next;
        node = node.next;
    }
    if (node && node.value === value) {
        last.next = node.next;
        if (node === this.end) {
            this.end = last;
            if (this.end === this.head) {
                return -1;
            }
        }
        return 1;
    }
    return 0;
}

/**
 * 删除链表头节点后的第一个节点
 * @return {number} -1:链表为空
 */
LinkedList.prototype.unshift = function() {
    if (this.head.next === this.end) {
        return -1;
    }
    this.head.next = this.head.next.next;
}

/**
 * Your LFUCache object will be instantiated and called as such:
 * var obj = new LFUCache(capacity)
 * var param_1 = obj.get(key)
 * obj.put(key,value)
 */
```

<br>

---

> 我的Github: github.com/ceynri 欢迎访问