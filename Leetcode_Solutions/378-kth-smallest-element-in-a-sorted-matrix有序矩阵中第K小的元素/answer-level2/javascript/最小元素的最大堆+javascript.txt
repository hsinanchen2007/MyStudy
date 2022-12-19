### 解题思路
不是最优解,但是对没排序的也可以用
先遍历矩阵,用最小元素建立大小为k的最大堆
然后堆顶元素就是第k个元素

### 代码

```javascript
/**
 * @param {number[][]} matrix
 * @param {number} k
 * @return {number}
 * 此题二分查找最快
 */
var kthSmallest = function(matrix, k) {
    let heap = buildHeap(matrix, k);
    return heap[1];
};
var buildHeap = function(matrix, k) {
    let heap = [0, matrix[0][0]];
    for(let i = 0;i<matrix.length; i++){
        for(let j = 0; j < matrix.length;j++){
            if(i===0 && j===0) continue;
            // 比堆顶元素大,则不入堆
            if(heap[1] < matrix[i][j] && heap.length > k){
                continue;
            } else{
                if(heap.length <= k) {
                    // 堆未满,入堆
                    insert(matrix[i][j]);
                } else {
                    // 堆已满,删除堆顶后入堆.
                    remove();
                    insert(matrix[i][j]);
                }
            }
        }
    }
    function insert(ele){
        heap.push(ele);
        let child = heap.length - 1;
        // 插入从下往上建堆
        while(child > 0) {
            let parent = parseInt(child / 2);
            if(parent > 0 && heap[parent] < heap[child]){
                [heap[child], heap[parent]] = [heap[parent], heap[child]];
                child = parent;
            } else {
                break;
            }
        }
    }
    function remove(){
        heap[1] = heap[heap.length - 1];
        heap.pop();
        let i = 1;
        // 删除 从上往下建堆
        while(true) {
            let maxPos = i;
            if(i * 2 < heap.length && heap[i] < heap[i * 2]){
                maxPos = i * 2
            } 
            if(i * 2 + 1 < heap.length  && heap[maxPos] < heap[i * 2 + 1]){
                maxPos = i * 2 + 1;
            }
            if(maxPos === i) break;
            [heap[i], heap[maxPos]] = [heap[maxPos], heap[i]];
            i = maxPos;
        }
    }
    return heap;
}
```