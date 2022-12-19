### 解题思路


### 代码

```java
class Solution {
    public int findKthLargest(int[] nums, int k) {
        // init heap 'the smallest element first'
        // 比较器有直接能初始化的
        // 这里可以是 PriorityQueue<Integer> bigHeap= new PriorityQueue<Integer>(k,Comparator.naturalOrder())；但是这个K是初始容量，不是固定容量。
        PriorityQueue<Integer> bigHeap= new PriorityQueue<Integer>(Comparator.naturalOrder());
        
        for(int i=0;i<nums.length;i++){
            bigHeap.add(nums[i]);
            if(bigHeap.size()>k){
                bigHeap.poll();
            }
            
        }
        return bigHeap.poll();
    }

}
```