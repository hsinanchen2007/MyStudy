### 解题思路
保存一个k个元素的小顶堆，前k个元素依次加入小顶堆（第k大的元素就是堆顶）。
后面的元素，首先和堆顶的元素比较，若大于堆顶的元素，则移除堆顶的元素，然后将该元素加入到堆中，那么这个堆始终保持着目前遍历的元素中第k大的元素在堆顶。

### 代码

```java
class Solution {
    public int findKthLargest(int[] nums, int k) {
        //维护一个K个元素的小顶堆
        PriorityQueue<Integer> pq = new PriorityQueue<>((o1, o2) -> o1-o2);
        for (int i = 0; i < nums.length; i++) {
            if (i < k)
                pq.add(nums[i]);
            else {
                if (pq.size() != 0 && nums[i] > pq.peek()){
                    pq.remove();
                    pq.add(nums[i]);
                }
            }
        }
        return pq.remove();
    }
}
```