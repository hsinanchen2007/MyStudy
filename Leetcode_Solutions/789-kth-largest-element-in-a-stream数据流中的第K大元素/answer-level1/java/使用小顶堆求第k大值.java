### 解题思路
1.构建一个k个元素的小顶堆（但是不需要排序，只需要保证第一个元素最小即可）
2.如果小顶堆满后，再添加元素，那么直接和堆顶元素进行比较。
2.1 如果大于堆顶元素，则重建堆；
2.2 如果小于或等于堆顶元素，则忽略。
heap[0]就是第k个最大元素

### 代码

```java
class KthLargest {

    int[] heap;
    
    int size = 0;
    
    public KthLargest(int k, int[] nums) {
        heap = new int[k];
        for (int num : nums) {
            add(num);
        }
    
        
    }
    
    public int add(int val) {
        if (size < heap.length) {
            size ++;
            heap[size-1] = val;
            
            
            if (size == heap.length) {
                sort(heap);
            }
        } else {
            if (heap[0] < val) {
                 heap[0] = val;
                adjustHeap(heap, 0, heap.length);
            }
        }
         
        
        return heap[0];
    }
    
    public void sort(int[] nums) {
        //构建小顶堆
    
        for (int i=nums.length/2-1; i>=0; i--) {
            adjustHeap(nums, i, nums.length);
        }
    }
    
    public void adjustHeap(int[] nums, int i, int length)
    {
        int temp = nums[i];
        for (int k=2*i+1; k<length; k=2*i+1) {
            if ((k+1<length) && nums[k]>nums[k+1]) {
                k++;
            }
            if (nums[k]<temp) {
                nums[i] = nums[k];
                i = k;
            } else {
                break;
            }
        }
        nums[i] = temp;
    }
}
```