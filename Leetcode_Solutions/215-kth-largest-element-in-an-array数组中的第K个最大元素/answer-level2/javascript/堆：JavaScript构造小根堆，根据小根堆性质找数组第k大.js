## js构造最小堆 堆中最后保存的最大的k个元素
### 解题思路
在小根堆中，堆顶的元素是最小的，如果堆顶的元素都比其他元素大，
那么堆里面的元素都比其他元素大，所以堆顶就是第k大元素
### 步骤
1. 从n个元素中截取前k个元素构造一个小根堆
2. for循环，依次从剩余n-k个元素中取出元素和堆顶比较，如果大于堆顶，则把值赋给堆顶，然后调整堆

### 用到的算法
1. 构造小根堆
数组保存堆中元素，从0开始，最后一个元素下标是n = arr.length-1
从最后一个非叶子结点开始(第一个非叶子结点 Math.floor((n-1)/2))，从右至左，从下至上进行调整。
- 调整方法：
  1. 比较arr[2*i+1],arr[2*i+2],将最小的与arr[i]交换，
  2. 交换后需要重新调整结构(把大的元素沉到底部)

2. 将剩余元素与堆顶比较

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var findKthLargest = function(nums, k) {
    var kHeap = nums.slice(0,k);
    makeHeap(kHeap);
    for(let i=k;k<nums.length;k++){
        updateHeap(kHeap,nums[k]);
    };   
    //取k个元素构造小顶堆
    function makeHeap(arr){
        var temp;
        for(let i = Math.floor((arr.length-2)/2);i>=0;i--){
            if(arr.length % 2==0 && 2*i+1 == arr.length-1){
                if(arr[2*i+1]<arr[i]){
                    temp = arr[i];
                    arr[i] = arr[2*i+1];
                    arr[2*i+1] = temp;
                }
            }else{
                if(arr[2*i+1]<=arr[2*i+2] && arr[2*i+1]<arr[i]){
                    temp = arr[2*i+1];
                    arr[2*i+1] = arr[i];
                    arr[i] = temp;
                    downHeap(arr,2*i+1,arr.length-1);
                }else if(arr[2*i+2]<arr[2*i+1] && arr[2*i+2]<arr[i]){
                    temp = arr[2*i+2];
                    arr[2*i+2] = arr[i];
                    arr[i] = temp;
                    downHeap(arr,2*i+2,arr.length-1);
                }
            }          
        }
    }
    //第i个元素向下 比较 下降
    function downHeap(arr,i,n){
        if(2*i+1>n){
            return;
        }else if(2*i+2 > n){
            if(arr[2*i+1]<arr[i]){
                temp = arr[i];
                arr[i] = arr[2*i+1];
                arr[2*i+1] = temp;                
            }
        }else{
            if(arr[2*i+1]<=arr[2*i+2] && arr[2*i+1]<arr[i]){
                temp = arr[2*i+1];
                arr[2*i+1] = arr[i];
                arr[i] = temp;
                downHeap(arr,2*i+1,arr.length-1);
            }else if(arr[2*i+2]<arr[2*i+1] && arr[2*i+2]<arr[i]){
                temp = arr[2*i+2];
                arr[2*i+2] = arr[i];
                arr[i] = temp;
                downHeap(arr,2*i+2,arr.length-1);
            }
        }
    }
    function updateHeap(heap, item){
        if(heap[0]<item){
            heap[0] = item;
            downHeap(heap,0,heap.length-1)
        }
    }
    return kHeap[0];
};
```