# 循环队列和指针
```
var MyCircularQueue = function(k) {
    this.front = 0
    this.rear = 0
    this.max = k
    this.list = Array(k)
};

/**
 * Insert an element into the circular queue. Return true if the operation is successful. 
 * @param {number} value
 * @return {boolean}
 */
MyCircularQueue.prototype.enQueue = function(value) {
    if(this.isFull()) {
        return false
    } else {
        this.list[this.rear] = value
        this.rear = (this.rear + 1) % this.max
        return true
    }
};

/**
 * Delete an element from the circular queue. Return true if the operation is successful.
 * @return {boolean}
 */
MyCircularQueue.prototype.deQueue = function() {
    let v = this.list[this.front]
    this.list[this.front] = undefined
    if(v !== undefined ) {
        this.front = (this.front + 1) % this.max
        return true
    } else {
        return false
    }
};

/**
 * Get the front item from the queue.
 * @return {number}
 */
MyCircularQueue.prototype.Front = function() {
    if(this.list[this.front] === undefined) {
        return -1
    } else {
        return this.list[this.front]
    }
};

/**
 * Get the last item from the queue.
 * @return {number}
 */
MyCircularQueue.prototype.Rear = function() {
    let rear = this.rear - 1
    if(this.list[rear < 0 ? this.max - 1 : rear] === undefined) {
        return -1
    } else {
        return this.list[rear < 0 ? this.max - 1 : rear] 
    }
};

/**
 * Checks whether the circular queue is empty or not.
 * @return {boolean}
 */
MyCircularQueue.prototype.isEmpty = function() {
    return this.front === this.rear && !this.list[this.front]
};

/**
 * Checks whether the circular queue is full or not.
 * @return {boolean}
 */
MyCircularQueue.prototype.isFull = function() {
    return (this.front === this.rear) && !!this.list[this.front]
};
```
