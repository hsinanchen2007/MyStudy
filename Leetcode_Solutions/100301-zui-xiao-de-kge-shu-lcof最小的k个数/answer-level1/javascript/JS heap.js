### 解题思路
这道题如果用sort来做，那简直是不要太简单。
但是这样肯定不是刷题的目的。
这道题用java做也很简单，有内置的堆可以用。
但是我们搞前端的，没有这样的内置数据结构怎么办？ 自己实现呀！！
下面我就是自己用JS实现了堆，可能不是最优的实现方法，因为我是按照堆的定义自己写的一个，没有参考网上的任何代码。
先来个堆的定义和特点吧，不知道小伙伴也可以顺便学习下。

  **注意堆是完全二叉树**

   堆的**特点**：插入的复杂度为 O(lgn) 删除的复杂度为 O(lgn), peak(取出最大或最小的元素) 的复杂度为 O(1);

1. 堆分为大根堆和小根堆, 大根堆只能查最大的元素，小根堆只能查最小的元素。

2. 并且堆是完全二叉树，也就是或是按照从上到小，从左到右依次建立。

3. 堆只保证，父节点比子节点大，不保证左右子节点谁更大。

3. 由于堆是完全二叉树，完全二叉树可以利用技巧设置。

   >  就是 我们用数组的第 0 项，存储越界信息，或者存储堆的长度，然后我们从数组的第1项开始存储数码。
   >
   >    这样可以保证，堆的每一项和数组的每一项都是一一对应的，heap[1] = 二叉树的根节点，
   >
   >    然后左孩子是 root * 2，右孩子是 root * 2 + 1
   >
   >    然后对于孩子来说，父节点始终是 self >> 1 或者说是 Math.floor(self / 2);  
## 插入   

我们对堆进行插入的时候，始终是将新元素放在完全二叉树的最末尾，然后再从最末尾开始向上比较，一点点向上浮。

## 删除   

1. 我们对对进行删除操作的时候，是相反的，我们们先取出第一个元素，然后把最后一项的值放在第一位，并且删除堆的最后一项，
2. 然后我们从第一项开始，向下沉，注意向下沉的时候是要将最小的孩子和自己交换的。

### 代码

```javascript
/**
 * @param {number[]} arr
 * @param {number} k
 * @return {number[]}
 */
class MinHeap{
    constructor(arr){
        this.heap = (arr && arr.sort((a, b) => a - b)) || ["empty!"];
    }
    push(newVal){
        let newIndex = this.heap.length;
        this.heap[newIndex] = newVal;//将新元素放在最后一个元素，然后向上调整。
        this.siftUp(newIndex);
    }
    /**向上调整的过程需要注意
     * 调整到index == 1的时候，说明已经到头了，就不需要调整了
     */
    siftUp(index){
        if(index == 1){
            return;
        }
        let father = (index >> 1);
        if(this.heap[index] < this.heap[father]){
            let temp = this.heap[index];
            this.heap[index] = this.heap[father];
            this.heap[father] = temp;
            this.siftUp(father);
        }else{
            return;
        }
    }
    pop(){
        if(this.heap.length == 2){
            return this.heap.pop();
        }
        if(this.heap.length == 1){
            return this.heap[0];
        }
        let res = this.heap[1];
        this.heap[1] = this.heap.pop(); // 将最后一个元素放到第一个元素，然后进行向下调整
        this.siftDown(1);
        return res;
    }
    /**向下调整的过程要进行判断
     * 首先，应该选择最小的那个元素交换，如果较小的孩子还是比自己大，那就不需要交换了，说明找到了位置
     * 如果右孩子不为空，那么就说明，左右孩子都不为空，那么就要与两个孩子都比较，然后交换
     * 如果右孩子为空，但是左孩子不为空，那么久要与左孩子比较，然后交换
     * 如果左孩子为空，就不需要再移动了，说明当前这个位置就是正确的
     */
    siftDown(index){
        let left = index * 2;
        let right = index * 2 + 1;
        if(this.heap[right] != undefined){
            let next = this.heap[left] < this.heap[right] ? left : right;
            if(this.heap[next] < this.heap[index]){
                let temp = this.heap[index];
                this.heap[index] = this.heap[next];
                this.heap[next] = temp;
                this.siftDown(next);
            }else{
                return;    
            }
        }else if(this.heap[left] != undefined){
            let next = left;
            if(this.heap[next] < this.heap[index]){
                let temp = this.heap[index];
                this.heap[index] = this.heap[next];
                this.heap[next] = temp;
            }else{
                return;    
            }
        }else if(this.heap[left] == undefined){
            return;
        }
    }
    peak(){
        return this.heap[1] || this.heap[0];
    }
}
var getLeastNumbers = function(arr, k) {
    let heap = new MinHeap();
    for(let i = 0; i < arr.length; i++){
        heap.push(arr[i]);
    }
    let res = [];
    for(let i = 0; i < k; i++){
        res.push(heap.pop());
    }
    return res;
};
```