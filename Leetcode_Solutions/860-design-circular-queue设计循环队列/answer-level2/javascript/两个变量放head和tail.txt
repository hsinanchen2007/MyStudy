### 解题思路
![image.png](https://pic.leetcode-cn.com/b498d481dc845e8e21d201f453c7fc1337cf717d27bdde4f0c65452f54c22211-image.png)

提交三次才AC，不难，但是要细心，首尾相连的情况要多想。
### 代码

```javascript
/**
 * Initialize your data structure here. Set the size of the queue to be k.
 * @param {number} k
 */
var MyCircularQueue = function (k) {
    this.cQueue = new Array();
    this.capacity = k
    this.head = -1;
    this.tail = -1;
};

/**
 * Insert an element into the circular queue. Return true if the operation is successful. 
 * @param {number} value
 * @return {boolean}
 */
MyCircularQueue.prototype.enQueue = function (value) {
    if (!this.isFull()) {
        if (this.tail > this.head) {
            if (this.tail < this.capacity - 1) {
                this.cQueue.push(value);
                this.tail++;
            } else {
                this.tail = 0;
                this.cQueue.unshift(value);
            }
        } else if (this.head === -1 && this.tail === -1) {
            this.cQueue.push(value);
            this.head++;
            this.tail++;
        } else {
            this.tail++;
            this.cQueue.splice(this.tail, 0, value);
        }
        return true;
    } else {
        return false;
    }
};

/**
 * Delete an element from the circular queue. Return true if the operation is successful.
 * @return {boolean}
 */
MyCircularQueue.prototype.deQueue = function () {
    if (this.isEmpty()) return false;
    this.cQueue.splice(this.head, 1)
    if (this.isEmpty()) {
        this.head = -1;
        this.tail = -1;
    } else {
        if (this.head <= this.capacity - 1) {
            if (this.head === 0) {
                this.tail--;
            } else {
                this.head++;
            }
        } else {
            this.head = 0;
        }
    }
    return true;
};

/**
 * Get the front item from the queue.
 * @return {number}
 */
MyCircularQueue.prototype.Front = function () {
    if (this.isEmpty()) return -1;
    return this.cQueue[this.head];
};

/**
 * Get the last item from the queue.
 * @return {number}
 */
MyCircularQueue.prototype.Rear = function () {
    if (this.isEmpty()) return -1;
    return this.cQueue[this.tail];
};

/**
 * Checks whether the circular queue is empty or not.
 * @return {boolean}
 */
MyCircularQueue.prototype.isEmpty = function () {
    return this.cQueue.length === 0;
};

/**
 * Checks whether the circular queue is full or not.
 * @return {boolean}
 */
MyCircularQueue.prototype.isFull = function () {
    return this.cQueue.length === this.capacity;
};
```