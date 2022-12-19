### 解题思路
![image.png](https://pic.leetcode-cn.com/822cb507a08274180d053cea6b468304b2193d0bc1d2a1e068f7c65c9efc07de-image.png)

就用了两个map，一个【key，value】，一个【frequency，keyArray[]】，然后就捣腾呗。

### 代码

```javascript
// 460. LFU Cache
// Design and implement a data structure for Least Frequently Used (LFU) cache. It should support the following operations: get and put.

// get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
// put(key, value) - Set or insert the value if the key is not already present. When the cache reaches its capacity, it should invalidate the least frequently used item before inserting a new item. For the purpose of this problem, when there is a tie (i.e., two or more keys that have the same frequency), the least recently used key would be evicted.

// Note that the number of times an item is used is the number of calls to the get and put functions for that item since it was inserted. This number is set to zero when the item is removed.

// Follow up:
// Could you do both operations in O(1) time complexity?

// Example:
// LFUCache cache = new LFUCache( 2 /* capacity */ );
// cache.put(1, 1);
// cache.put(2, 2);
// cache.get(1);       // returns 1
// cache.put(3, 3);    // evicts key 2
// cache.get(2);       // returns -1 (not found)
// cache.get(3);       // returns 3.
// cache.put(4, 4);    // evicts key 1.
// cache.get(1);       // returns -1 (not found)
// cache.get(3);       // returns 3
// cache.get(4);       // returns 4

/**
 * @param {number} capacity
 */
var LFUCache = function (capacity) {
    this.capacity = capacity;
    this.m = new Map();
    this.frqM = new Map(); // frequency, [key1, key2..]
};

const addFrequency = (m, key, isCreate) => {
    if (isCreate) {
        if (!m.has(1)) {
            m.set(1, [key]);
        } else {
            let kArr = m.get(1);
            kArr.push(key);
            m.set(1, kArr);
        }
        return void 0;
    }
    let newFrq = 0;
    for (let [frq, kArr] of m) {
        if (kArr.includes(key)) {
            newFrq = frq + 1;
            kArr.splice(kArr.indexOf(key), 1);
            if (!kArr.length) {
                m.delete(frq);
                break;
            }
        }
    }
    if (m.has(newFrq)) {
        let kArr = m.get(newFrq);
        kArr.push(key);
        m.set(newFrq, kArr)
    } else {
        m.set(newFrq, [key]);
    }
}
/** 
 * @param {number} key
 * @return {number}
 */
LFUCache.prototype.get = function (key) {
    if (this.capacity === 0) return -1;
    if (this.m.has(key)) {
        addFrequency(this.frqM, key, false);
        return this.m.get(key);
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
    if (this.capacity === 0) return void 0;
    if (this.m.size < this.capacity || this.m.has(key)) {
        if (!this.m.has(key)) {
            addFrequency(this.frqM, key, true);
        } else {
            addFrequency(this.frqM, key, false);
        }
    } else {
        let frqArr = Array.from(this.frqM.keys());
        frqArr.sort((a, b) => a - b);
        let lowFrqKeyArr = this.frqM.get(frqArr[0]);
        toDel = lowFrqKeyArr.shift();
        if (!lowFrqKeyArr.length) {
            this.frqM.delete(frqArr[0]);
        } else {
            this.frqM.set(frqArr[0], lowFrqKeyArr)
        }
        this.m.delete(toDel);
        addFrequency(this.frqM, key, true);
    }
    this.m.set(key, value);
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * var obj = new LFUCache(capacity)
 * var param_1 = obj.get(key)
 * obj.put(key,value)
 */
```