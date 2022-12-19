![image.png](https://pic.leetcode-cn.com/4c162ad3594d22421a243467a4f9d645e2b0b9face10991c988cf4555eed6484-image.png)

```
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
function swap(arr, i ,j) {
    var temp = arr[i];
    arr[i] = arr[j];
    arr[j]= temp;
}

function heapify(arr, x, length) {
    var l = 2*x+1;
    var r = 2*x+2;
    var largest = x;
    if(l<length && arr[l] > arr[largest]) {
        largest = l;
    }
    if(r<length && arr[r] > arr[largest]) {
        largest = r;
    }
    if(largest!= x) {
        swap(arr, x, largest);
        // 递归交换以下的是否也建好堆.
        heapify(arr, largest, length);
    }
}

var findKthLargest = function(nums, k) {
    var size = nums.length;
    // 建立堆
    for(var i = parseInt(size/2)+1 ; i >=0 ;i --) {
        heapify(nums, i, size);
    }
    // 排序
    for(var j= size-1; j>=size-k; j--) {
        // 得到本次的最大，将最大的与最后一个交换位子
        swap(nums, 0, j);
        heapify(nums, 0, j);
    }
    return nums[size-k];
}
```