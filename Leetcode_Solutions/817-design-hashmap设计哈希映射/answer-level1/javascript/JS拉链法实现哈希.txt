本题是模板题。哈希常用的方法是`拉链法`和`开放寻址法`，要注意的是如果用`开放寻址法`的话，开槽的范围一般是数据的2 ~ 3倍。
还有就是有些人用js的object去做也是错的，本题的考点就是哈希的实现，那种属于作弊了，而且面试官也肯定不会同意的。

![image.png](https://pic.leetcode-cn.com/56da441befb06c870c69e5d37ab760f80831b6eedaaa2d70ed9a5d62e9159efa-image.png)

js实现如下：
```js
/**
 * Initialize your data structure here.
 */
function LinkNode(key, val) {
    this.key = key;
    this.val = val;
    this.next = null;
}

var MyHashMap = function() {
    const N = 1e4 +3;
    const hash = new Array(N);
    for (let i = 0; i < hash.length; i++) hash[i] = new LinkNode();

    this.hash = hash;
};

/**
 * value will always be non-negative. 
 * @param {number} key 
 * @param {number} value
 * @return {void}
 */
MyHashMap.prototype.put = function(key, value) {
    const N = 1e4 +3;
    const index = key % N;
    const head = this.hash[index];
    let curr = head;

    while (curr && curr.next) {
        if (curr.next.key === key) {
            curr.next.val = value;
            return;
        }
        curr = curr.next;
    }

    const node = new LinkNode(key, value);
    curr.next = node;
};

/**
 * Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key 
 * @param {number} key
 * @return {number}
 */
MyHashMap.prototype.get = function(key) {
    const N = 1e4 +3;
    const index = key % N;
    const head = this.hash[index];
    let curr = head;

    while (curr && curr.next) {
        if (curr.next.key === key) return curr.next.val;
        curr = curr.next;
    }
    return -1;
};

/**
 * Removes the mapping of the specified value key if this map contains a mapping for the key 
 * @param {number} key
 * @return {void}
 */
MyHashMap.prototype.remove = function(key) {
    const N = 1e4 +3;
    const index = key % N;
    const head = this.hash[index];
    let curr = head;

    while (curr && curr.next) {
        if (curr.next.key === key) {
            curr.next = curr.next.next;
            return;
        } else {
            curr = curr.next;
        }
    }
};

/** 
 * Your MyHashMap object will be instantiated and called as such:
 * var obj = new MyHashMap()
 * obj.put(key,value)
 * var param_2 = obj.get(key)
 * obj.remove(key)
 */
```