

```java
class Solution {
    public int findKthLargest(int[] nums, int k) {
          //利用最小堆，创建K+1的size,遍历数组元素进行添加，并poll出一个。
          //最后遍历结束剩下的第K个中，第一个就是最大的。
          PriorityQueue<Integer> largeK = new PriorityQueue<Integer>(k + 1);
                for(int el : nums) {
                    largeK.add(el);
                    if (largeK.size() > k) {
                        largeK.poll();
                    }
                }
                return largeK.poll(); 
    }
}
```