```javascript []
/**
 * Initialize your data structure here.
 */
var MyHashSet = function() {
  this.hash = val => val % 100;
  this.buckets = [];
};

/**
 * @param {number} key
 * @return {void}
 */
MyHashSet.prototype.add = function(key) {
  if (!this.buckets[this.hash(key)]) this.buckets[this.hash(key)] = [];
  const bucket = this.buckets[this.hash(key)];
  if (bucket.indexOf(key) === -1) {
    this.buckets[this.hash(key)].push(key);
  }
};

/**
 * @param {number} key
 * @return {void}
 */
MyHashSet.prototype.remove = function(key) {
  const bucket = this.buckets[this.hash(key)] || [];
  const index = bucket.indexOf(key);
  if (index > -1) {
    bucket.splice(index, 1);
  }
};

/**
 * Returns true if this set contains the specified element
 * @param {number} key
 * @return {boolean}
 */
MyHashSet.prototype.contains = function(key) {
  const bucket = this.buckets[this.hash(key)];
  return bucket ? bucket.indexOf(key) > -1 : false;
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * var obj = new MyHashSet()
 * obj.add(key)
 * obj.remove(key)
 * var param_3 = obj.contains(key)
 */

```