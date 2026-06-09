### 解题思路
&emsp;&emsp;官方解法解释已经很明确了，我只是添加下js版本的代码（主要是堆和快速选择）。因为原生js没那么多轮子所以简单的造一下。

### 代码
```javascript []
var findKthLargest = function(nums, k) {
    //堆
    function Heap(){
        this.heap = [];
        //leftNode: 2 * i + 1,
        //rightNode: 2 * i + 2;
        this.getTop = function(){
            return this.heap[0];
        }
        this.insert = function(num){
            this.heap.push(num);
            let idx = this.heap.length - 1,
                fatherIndex = Math.floor((idx - 1) / 2);
            while(fatherIndex >= 0 && this.heap[idx] < this.heap[fatherIndex]){
                [this.heap[idx], this.heap[fatherIndex]] = [this.heap[fatherIndex], this.heap[idx]];
                idx = fatherIndex;
                fatherIndex = Math.floor((idx - 1) / 2);
            }
        }
        this.remove = function(num){
            if(this.heap.length == 1 && num == undefined){
                return this.heap.pop();
            }
            let res = this.heap[0];
            num = num == undefined ? this.heap.pop() : num;
            this.heap[0] = num;
            let idx = 0,
                left = 2 * idx + 1,
                right = 2 * idx + 2;
            while(this.heap[idx] > this.heap[left] || this.heap[idx] > this.heap[right]){
                if(this.heap[left] > this.heap[right]){
                    [this.heap[right], this.heap[idx]] = [this.heap[idx], this.heap[right]];
                    idx = right;
                }else{
                    [this.heap[left], this.heap[idx]] = [this.heap[idx], this.heap[left]];
                    idx = left
                }
                left = 2 * idx + 1;
                right = 2 * idx + 2;
            }
            return res;
        }
    }

    let heap = new Heap();
    for(let i = 0; i < nums.length; i++){
        if(i < k){
            heap.insert(nums[i]);
        }else if(nums[i] > heap.getTop()){
            heap.remove(nums[i]);
        }
    }
    return heap.getTop();

    //快速选择
    return findKthNumber(nums, nums.length - k + 1);
    
    function findKthNumber(arr, k, p = 0, q = arr.length){
        function helper(nums, start, end){
            let random =(Math.random() * (end - start - 1) + start) | 0;
            [nums[random], nums[end - 1]] = [nums[end - 1], nums[random]];
            let x = nums[end - 1];
            let index = start;
            for(let i = start; i < end - 1; i++){
                if(nums[i] < x){
                    [nums[index], nums[i]] = [nums[i], nums[index]];
                    index++;
                }
            }
            [nums[end - 1], nums[index]] = [nums[index], nums[end - 1]];
            return index;
        }
        if(p == q) return arr[p];
        let index = helper(arr, p, q),
            i = index - p + 1;
        if (i == k) return arr[index];
        return i > k ? findKthNumber(arr, k, p, index) : findKthNumber(arr, k - i, index + 1, q)
    }
};
```
