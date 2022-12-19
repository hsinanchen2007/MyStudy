### 解题思路
折腾死了

### 代码

```javascript
/**
 * @param {number} capacity
 */
var LFUCache = function(capacity) {
    this.capacity = capacity;
    this._capacity = capacity;
    this.keyMap = new Map();
    this.freqMap = new Map();
    this.minFreq = 1;
};

/** 
 * @param {number} key
 * @return {number}
 */
LFUCache.prototype.get = function(key) {
    const target = this.keyMap.get(key);
    if (!target) {
        return -1;
    }
    this.update(target);
    return target.value;
};

/** 
 * @param {number} key 
 * @param {number} value
 * @return {void}
 */
LFUCache.prototype.put = function(key, value) {
    const {minFreq, freqMap, keyMap, capacity, _capacity} = this;
    if  (capacity < 1) {
        return undefined;
    }
    let target = keyMap.get(key);
    if (target) {
        target.value = value;
    } else {
        if (_capacity > 0) {
            this._capacity -= 1;
        } else {
            let freqInfo = freqMap.get(minFreq);
            let {key} = freqInfo.shift();
            keyMap.delete(key);
            if (freqInfo.empty()) {
                freqMap.delete(minFreq);
            }
        }
        target = {
            key, value, freq: 0
        };
        keyMap.set(key, target);
    }
    this.update(target);
};

LFUCache.prototype.update = function (target) {
    const {freqMap, minFreq} = this;
    let {freq} = target;
    if (freq > 0) {
        let freqInfo = freqMap.get(freq);
        freqInfo.remove(target);
        if (freqInfo.empty()) {
            freqMap.delete(freq);
            if (freq === minFreq) {
                this.minFreq += 1;
            }
        }
    } else {
        this.minFreq = 1;
    }
    freq++;
    target.freq = freq;
    freqInfo = freqMap.get(freq);
    if (!freqInfo) {
        freqInfo = new Link();
        freqMap.set(freq, freqInfo);
    }
    freqInfo.push(target);
}

class Link {
    constructor() {
        this.begin = null;
        this.end = null;
    }

    shift() {
        const {begin} = this;
        if (begin) {
            this.begin = null;
            const {next} = begin;
            if (next) {
                next.pre = null;
                begin.next = null;
                this.begin = next;
            } else {
                this.end = null;
            }
        }
        return begin;
    }

    remove(target) {
        const {pre,  next} = target;
        if (pre) {
            pre.next = next;
            target.pre = null;
        } else {
            this.begin = next;
        }
        if (next)  {
            next.pre = pre;
            target.next = null;
        } else {
            this.end = pre;
        }
    }

    push(node) {
        const {begin, end}  = this;
        if (!begin) {
            this.begin = node;
        }
        if (end) {
            end.next = node;
            node.pre = end;
        }
        this.end = node;
    }

    empty() {
        return !this.begin;
    }
}

/**
 * Your LFUCache object will be instantiated and called as such:
 * var obj = new LFUCache(capacity)
 * var param_1 = obj.get(key)
 * obj.put(key,value)
 */
```