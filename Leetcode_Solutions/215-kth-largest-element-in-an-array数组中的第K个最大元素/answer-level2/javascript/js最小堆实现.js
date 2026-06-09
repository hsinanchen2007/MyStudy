保障一个只有k长度的最小堆（完全二叉树）
在js中用数组表示
堆顶就是第k大的数字
```
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */

// 最小堆
class MinHeap {
    heap = []

    swap (index1, index2) {
        let temp = this.heap[index1]
        this.heap[index1] = this.heap[index2]
        this.heap[index2] = temp
    }

    getLeftNode(index) {
        return (index + 1) * 2 - 1
    }

    getRightNode(index) {
        return (index + 1) * 2 
    }

    getParentNode(index) {
        if(index === 0) 
            return undefined
        
        return (index - 1) >> 1
    }

    // 向上移动
    shiftUp(index) {
        let parentIndex = this.getParentNode(index)
        if(index != 0 && (this.heap[parentIndex] > this.heap[index] )) {
            this.swap(parentIndex, index)
            this.shiftUp(parentIndex)
        }
    }

    // 向下
    shitDown(index) {

        let rightIndex = this.getRightNode(index),
            leftIndex = this.getLeftNode(index)

        if(leftIndex < this.heap.length && (this.heap[leftIndex] < this.heap[index])) {
            this.swap(index, leftIndex)
            this.shitDown(leftIndex)
        }
        if(rightIndex < this.heap.length && (this.heap[rightIndex] < this.heap[index])) {
            this.swap(rightIndex, index)
            this.shitDown(rightIndex)
        }
    }

    insert(value) {
        this.heap.push(value)
        this.shiftUp(this.heap.length - 1)
    }
}

var findKthLargest = function(nums, k) {
    let arr = new MinHeap()

    for(let i = 0 ; i < nums.length; i++) {
        if(i < k) {
            arr.insert(nums[i])
        }else{
            if (nums[i] >= arr.heap[0]) {

                arr.heap[0] = nums[i]
                arr.shitDown(0)
            }
        }
    }


    return arr.heap[0]
};
```
