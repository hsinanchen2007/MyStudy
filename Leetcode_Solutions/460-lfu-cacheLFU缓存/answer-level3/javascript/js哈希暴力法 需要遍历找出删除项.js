### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
   * @param {number} capacity
   */
  var LFUCache = function(capacity) {
    this.cache = {};
    this.useIndex = 0;
    this.capacity = capacity;
    this.count = 0;
    this.latest = null;
  };

  /**
   * @param {number} key
   * @return {number}
   */
  LFUCache.prototype.get = function(key) {
    if (key in this.cache) {
      this.cache[key].usage++;
      this.cache[key].useIndex = ++this.useIndex;
      return this.cache[key].value;
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
    if (!this.capacity) return;
    if (key in this.cache) {
      this.cache[key].value = value;
      this.cache[key].usage++;
      this.cache[key].useIndex = ++this.useIndex;
      return;
    }
    this.count++;
    if (this.count > this.capacity) {
      let min = Infinity, keyName;
      for (let k in this.cache) {
        if (this.cache[k].usage < min) {
          keyName = k;
          min = this.cache[k].usage;
        } else if (this.cache[k].usage === min){
          if (this.cache[keyName].useIndex > this.cache[k].useIndex) {
            keyName = k;
          }
        }
      }
      delete this.cache[keyName];
    }
    this.cache[key] = {
      value: value,
      useIndex: ++this.useIndex,
      usage: 0
    };
  };
```