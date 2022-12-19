### 解题思路
利用高级数据结构，可以完成。
### 代码

```java
class Solution {
    public int findKthLargest(int[] nums, int k) {
        PriorityQueue<Integer> queue = new PriorityQueue<>((x,y)->y-x);
        for(int i : nums){
            queue.offer(i);
        }
        int temp = 0;
        while(k-- > 0){
           temp = queue.poll();
        }
        return temp;
    }
}
```