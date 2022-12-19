### 解题思路
构建一个最大堆，一个最小堆
有两个条件
1.堆的长度差<=1
2.最大堆的堆顶比最小堆的堆顶小，这样就能保证最大堆中所有数字都比最小堆小
如果两者的长度相同，那么当插入数字大于最大堆堆顶时，直接将数字插入最小堆中否则插入最大堆中
如果最大堆比最小堆长度小，当num大于最小堆堆顶时，为了保障条件1，将最小堆堆顶插入最大堆中，自己的堆顶弹出，并将num插入最大堆中
                    当num小于最小堆堆顶时，可以直接插入最大堆中
如果最大堆比最小堆长度达同理上一个

### 代码

```javascript
/**
 * initialize your data structure here.
 */

class MinHeap {
    heap = []

    swap(index1, index2) {
        let temp = this.heap[index1]
        this.heap[index1] = this.heap[index2]
        this.heap[index2] = temp
    }

    insert(value) {
        this.heap.push(value)
        this.shiftUp(this.heap.length - 1)
    }

    shiftUp(index) {
        let parentNodeIndex = (index - 1) >> 1
        if (index != 0 && this.heap[index] < this.heap[parentNodeIndex]){
            this.swap(parentNodeIndex, index)
            this.shiftUp(parentNodeIndex)
        }

    }

    shiftDown(index) {
        let leftNodeIndex = (index + 1) * 2 - 1,
            rightNodeIndex = (index + 1) * 2

        if(leftNodeIndex  < this.heap.length && this.heap[leftNodeIndex] < this.heap[index]) {
            this.swap(index, leftNodeIndex)
            this.shiftDown(leftNodeIndex)
        }
        if(rightNodeIndex < this.heap.length && this.heap[rightNodeIndex] < this.heap[index]) {
            this.swap(index, rightNodeIndex)
            this.shiftDown(rightNodeIndex)
        }
    }
}

class BigHeap {
    heap = []

    swap(index1, index2) {
        let temp = this.heap[index1]
        this.heap[index1] = this.heap[index2]
        this.heap[index2] = temp
    }

    insert(value) {
        this.heap.push(value)
        this.shiftUp(this.heap.length - 1)
    }

    shiftUp(index) {
        let parentNodeIndex = (index - 1) >> 1
        if (index != 0 && this.heap[index] > this.heap[parentNodeIndex]){
            this.swap(parentNodeIndex, index)
            this.shiftUp(parentNodeIndex)
        }

    }

    shiftDown(index) {
        let leftNodeIndex = (index + 1) * 2 - 1,
            rightNodeIndex = (index + 1) * 2

        if(leftNodeIndex  < this.heap.length && this.heap[leftNodeIndex] > this.heap[index]) {
            this.swap(index, leftNodeIndex)
            this.shiftDown(leftNodeIndex)
        }
        if(rightNodeIndex < this.heap.length && this.heap[rightNodeIndex] > this.heap[index]) {
            this.swap(index, rightNodeIndex)
            this.shiftDown(rightNodeIndex)
        }
    }
}


var MedianFinder = function() {
    this.mini_heap = new MinHeap()
    this.big_heap = new BigHeap()
};

/** 
 * @param {number} num
 * @return {void}
 */
MedianFinder.prototype.addNum = function(num) {
    // 添加操作
    if (this.mini_heap.heap.length == this.big_heap.heap.length) {
        if (num > this.big_heap.heap[0]) {
            this.mini_heap.insert(num)
        }else {
            this.big_heap.insert(num)
        }
    }else if(this.mini_heap.heap.length > this.big_heap.heap.length) {
        if(num < this.mini_heap.heap[0]) {
            this.big_heap.insert(num)
        }else {
            // 本来应该加到最小堆
            //把最小堆堆顶给最大堆，自己的堆顶换成num
            this.big_heap.insert(this.mini_heap.heap[0])
            this.mini_heap.heap[0] = num
            this.mini_heap.shiftDown(0)
        }
    }else if(this.mini_heap.heap.length < this.big_heap.heap.length) {
        if(num > this.big_heap.heap[0]) {
            this.mini_heap.insert(num)
        }else {
            this.mini_heap.insert(this.big_heap.heap[0])
            this.big_heap.heap[0] = num
            this.big_heap.shiftDown(0)
        }
    }
    // console.log(this.big_heap, this.mini_heap)
};

/**
 * @return {number}
 */
MedianFinder.prototype.findMedian = function() {
    // 比较最大/小堆的大小
    if (this.mini_heap.heap.length == this.big_heap.heap.length) {
        return (this.mini_heap.heap[0] + this.big_heap.heap[0]) / 2
    }else if (this.mini_heap.heap.length > this.big_heap.heap.length) {
        return this.mini_heap.heap[0]
    }else {
        return this.big_heap.heap[0]
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * var obj = new MedianFinder()
 * obj.addNum(num)
 * var param_2 = obj.findMedian()
 */
```