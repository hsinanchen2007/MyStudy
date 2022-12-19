### 解题思路

### 代码

```java
class MedianFinder {
    /*
    动态维护一个大顶堆 max_heap 和一个小顶堆 min_heap，
    这两个堆各自存放“一半”的数据（这里的“一半”是指两个堆的size()相差小于等于1），
    且维持 max_heap 的堆顶 <= min_heap 的堆顶。
    在插入新元素x时，如果max_heap为空，直接将x压入max_heap；
    否则，先比较 max_heap.size() 与 min_heap.size()：
        若max_heap与min_heap元素个数相同：
            若 x < max_heap 的堆顶，将x压入 max_heap；
            否则，将x压入 min_heap；
        若 max_heap 比 min_heap 的size小（需要通过调整两个堆，以保证平衡）：
            若 x < max_heap 的堆顶，直接将x压入 max_heap；
            否则，为了总是保持min_heap>=max_heap,先将x压入min_heap, 再将 min_heap 的堆顶弹出并压入 max_heap
       若 max_heap 比 min_heap 的size大（同样需要通过调整两个堆）：
            若 x > max_heap 的堆顶，直接将x压入 min_heap；
            否则，为了总是保持min_heap>=max_heap,先将x压入max_heap, 再将max_heap 的堆顶弹出并压入 min_heap
    */

    //先创建大顶堆与小顶堆
    int SIZE = 20000;
    int[] maxHeap = null;
    int[] minHeap = null;
    int len1 = 0;
    int len2 = 0;

    /** initialize your data structure here. */
    public MedianFinder() {
        maxHeap = new int[SIZE];
        minHeap = new int[SIZE];
    }
    
    public void addNum(int num) {
        if(len1==0){
            maxHeap[len1++] = num;
        }else{
            if(len1==len2){
                if(num<maxHeap[0]){
                    addMaxHeapNum(maxHeap,num);
                }else{
                    addMinHeapNum(minHeap,num);
                }
            }else if(len1<len2){
                if(num<maxHeap[0]){
                    addMaxHeapNum(maxHeap,num);
                }else{
                    addMinHeapNum(minHeap,num);
                    addMaxHeapNum(maxHeap,minHeap[0]);
                    swap(minHeap,0,len2-1);
                    len2--;
                    adjustMin(minHeap,0,len2);
                }
            }else{
                if(num>maxHeap[0]){
                    addMinHeapNum(minHeap,num);
                }else{
                    addMaxHeapNum(maxHeap,num);
                    addMinHeapNum(minHeap,maxHeap[0]);
                    swap(maxHeap,0,len1-1);
                    len1--;
                    adjustMax(maxHeap,0,len1);
                }
            }
        }
    }

    public double findMedian() {
        if(len1<len2){
            return minHeap[0];
        }else if(len1==len2){
            return (maxHeap[0]+minHeap[0])/2.0;
        }else{
            return maxHeap[0];
        }
    }

    //将数据加入大顶堆中
    private void addMaxHeapNum(int[] maxHeap, int num){
        maxHeap[len1++] = num;
        for(int i=len1/2;i>=0;i--){
            adjustMax(maxHeap,i,len1);
        }
    }

    //将数据加入小顶堆中
    private void addMinHeapNum(int[] minHeap, int num){
        minHeap[len2++] = num;
        for(int i=len2/2;i>=0;i--){
            adjustMin(minHeap,i,len2);
        }
    }

    // 调整大顶堆
    private void adjustMax(int[] nums, int i, int len){
        int left = i*2+1;
        int right = i*2+2;
        int max = i;
        if(left<len && nums[max]<nums[left]){
            max = left;
        }
        if(right<len && nums[max]<nums[right]){
            max = right;
        }
        if(max!=i){
            swap(nums,i,max);
            adjustMax(nums,max,len);
        }
    }

    //调整小顶堆
    private void adjustMin(int[] nums, int i, int len){
        int left = i*2+1;
        int right = i*2+2;
        int min = i;
        if(left<len && nums[min]>nums[left]){
            min = left;
        }
        if(right<len && nums[min]>nums[right]){
            min = right;
        }
        if(min!=i){
            swap(nums,i,min);
            adjustMin(nums,min,len);
        }
    }

    private void swap(int[] nums, int i, int j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
```