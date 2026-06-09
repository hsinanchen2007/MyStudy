** 思路：将有序列表分为大小根堆，左侧为大根堆，右侧为小根堆，从而将中位数变成求取大小根堆的根值。 **

    class Heap {
      constructor(iLarge = true){
        this.heap = new Array();
        this.isLarge = iLarge;
      }

      swap(id1, id2) {
        let temp = this.heap[id1];
        this.heap[id1] = this.heap[id2];
        this.heap[id2] = temp;
      }

      up(id) {
        let pid = Math.floor((id - 1) / 2);

        if(this.isLarge){
          if(id !== 0 && this.heap[pid] < this.heap[id]){
            this.swap(pid, id);
            this.up(pid);
          }
        } else {
          if(id !== 0 && this.heap[pid] > this.heap[id]){
            this.swap(pid, id);
            this.up(pid);
          }
        }
      }

      down(id) {
        let leftChildId = id * 2 + 1;
        let rightChildId = id * 2 + 2;
        let len = this.heap.length;

        if(this.isLarge){
          if(leftChildId < len && this.heap[leftChildId] > this.heap[id]){
            this.swap(leftChildId, id);
            this.down(leftChildId);
          }

          if(rightChildId < len && this.heap[rightChildId] > this.heap[id]){
            this.swap(rightChildId, id);
            this.down(rightChildId);
          }
        } else {
          if(leftChildId < len && this.heap[leftChildId] < this.heap[id]){
            this.swap(leftChildId, id);
            this.down(leftChildId);
          }

          if(rightChildId < len && this.heap[rightChildId] < this.heap[id]){
            this.swap(rightChildId, id);
            this.down(rightChildId);
          }
        }
      }

      insert(x) {
        this.heap.push(x);
        this.up(this.heap.length - 1);
      }

      remove(){
        this.swap(0, this.heap.length - 1);
        const ret = this.heap.pop();

        this.down(0);

        return ret;
      }

      pop(){
        return this.heap.pop();
      }

      getRoot(){
        return this.heap[0]
      }

      getLength(){
        return this.heap.length;
      }
    }

    /**
     * initialize your data structure here.
     */
    var MedianFinder = function() {
      // 思路：大小根堆 ， 左边为大根堆， 右边为小根堆
      this.left = new Heap(true);
      this.right = new Heap(false);
    };

    /**
     * @param {number} num
     * @return {void}
     */
    MedianFinder.prototype.addNum = function(num) {
        // 具体算法： 如果num 大于 left 的最大值，则添加到右侧，添加完成后需要做大小根的平衡操作。
        if(num > this.left.getRoot()){
          this.right.insert(num);

          // 大小根平衡操作
          if(this.right.getLength() > this.left.getLength()){
            this.left.insert(this.right.remove());
          }
        } else{
          this.left.insert(num);

          if(this.left.getLength() > (this.right.getLength() + 1)){
            this.right.insert(this.left.remove());
          }
        }
    };

    /**
     * @return {number}
     */
    MedianFinder.prototype.findMedian = function() {
      let len = this.left.getLength() + this.right.getLength();

      if(len % 2 === 0){
        return (this.left.getRoot() + this.right.getRoot()) / 2;
      } else{
        return this.left.getRoot();
      }
    };
