通过heapify构造一个最大堆 算法复杂度O(nlogk)

```
class Heap {

  constructor() {
    this.data = []

    this.parentIdx = i => Math.round((i - 1) / 2)
    this.leftChildIdx = i => 2 * i + 1
    this.rightChildIdx =  i => 2 * i + 2
  }

  top() {
    let data = this.data[0]

    this.swap(0, this.data.length - 1)

    delete this.data[this.data.length - 1]
    this.data.length--

    this.shiftDown(0)

    return data
  }

  add(val) {
    this.data.push(val)
    this.shiftUp(this.data.length - 1)
  }

  heapify(data) {
    this.data = data

    for (let i = this.parentIdx(this.data.length - 1); i >= 0; i--) {
      this.shiftDown(i)
    }
  }

  shiftDown(i) {
    let k = i
    while(this.leftChildIdx(k) < this.data.length &&
         (this.node(k) < this.leftChild(k) ||
          this.node(k) < this.rightChild(k))) {
      if(this.rightChild(k) > this.leftChild(k)) {
        this.swap(this.rightChildIdx(k), k)
        k = this.rightChildIdx(k)
      } else {
        this.swap(this.leftChildIdx(k), k)
        k  = this.leftChildIdx(k)
      }
    }
  }

  shiftUp(i) {
    let k = i

    while (this.parent(k) < this.node(k)) {
      this.swap(this.parentIdx(k), k)
      k = this.parentIdx(k)
    }
  }

  parent(i) {
    return this.data[this.parentIdx(i)]
  }

  leftChild(i) {
    return this.data[this.leftChildIdx(i)]
  }

  rightChild(i) {
    return this.data[this.rightChildIdx(i)]
  }

  node(i) {
    return this.data[i]
  }

  swap(i, j) {
    let tmp = this.data[i]
    this.data[i] = this.data[j]
    this.data[j] = tmp
  }
}

var findKthLargest = function(nums, k) {
  const heap = new Heap()
  heap.heapify(nums)

  while (k > 1) {
    heap.top()
    k--
  }

  return heap.top()
}
```
