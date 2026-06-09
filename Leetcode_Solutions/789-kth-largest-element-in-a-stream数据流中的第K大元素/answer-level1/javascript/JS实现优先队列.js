解题思路
用JS实现一个优先队列（MinHeap）

```javascript
function MinHeap(initData = []) {
  this.heap = initData;
}

MinHeap.prototype = {
  constructor: MinHeap,
  size() {
    return this.heap.length;
  },
  getMin() {
    return this.heap[0];
  },
  extractMin() {
    let size = this.heap.length;
    if(size <= 1){
      this.heap = [];
      return this.heap[0];
    }else{
      let min = this.heap[0];
      this.heap[0] = this.heap.pop();  //将最后一个节点移动至第一个
      this.minHeapify(0); //重新排序堆
      return min;
    }
  },
  insert(num) {
    this.heap.push(num);
    let curIndex = this.size() - 1, parentIndex = Math.floor((curIndex + 1)/2 -1);
    while (this.heap[curIndex] < this.heap[parentIndex]) {
      this.swapPosition(curIndex, parentIndex);
      curIndex = parentIndex;
      parentIndex = Math.floor((curIndex + 1)/2 -1);
    }
  },
  swapPosition(index1, index2) {
    [this.heap[index2], this.heap[index1]] = [this.heap[index1], this.heap[index2]];
  },
  minHeapify(index) {
    if(this.size() >= index && this.size() > 1){ //只有当size大于index且大于1时才重排
      let leftIndex = 2 * index + 1, rightIndex = 2 * (index + 1);
      let cur = this.heap[index], left = this.heap[leftIndex], right = this.heap[rightIndex];
      if(cur > left || cur > right){
        //比较左右节点大小， 替换小的
        let targetIndex = left < right || right === undefined ? leftIndex : rightIndex;
        this.swapPosition(index, targetIndex)
        this.minHeapify(targetIndex); 
      }
    }
  }
}
/**
 * @param {number} k
 * @param {number[]} nums
 */
var KthLargest = function(k, nums) {
  this.minHeap = new MinHeap();
  this.k = k;
  nums.forEach(num => {
    this.add(num);
  })
};

/** 
 * @param {number} val
 * @return {number}
 */
KthLargest.prototype.add = function(val) {
  let min = this.minHeap.getMin();
  if(val > min || this.minHeap.size() < this.k){
    this.minHeap.insert(val);
    if(this.minHeap.size() > this.k){
      this.minHeap.extractMin();
    }
  } 
  return this.minHeap.getMin();
};
```
