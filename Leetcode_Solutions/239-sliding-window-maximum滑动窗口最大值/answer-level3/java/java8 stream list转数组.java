### 解题思路
java8 stream list转数组

### 代码

```java
class Solution {
    public static int[] maxSlidingWindow(int[] nums, int k) {
        int[] res = new int[nums.length - k +1];
        List<Integer> resList = new LinkedList<>();
        Deque<Integer> deque = new ArrayDeque<>();

        for (int i = 0; i < nums.length; i++) {
            while (!deque.isEmpty() && nums[i] > nums[deque.peekLast()]) {
                deque.pollLast();
            }
            deque.offerLast(i);
            if((i-deque.peekFirst()) == k){
                deque.pollFirst();
            }
            if (i >= k - 1) {
                resList.add(nums[deque.peekFirst()]);
            }
        }
        int[] ee =  resList.stream().mapToInt(Integer::intValue).toArray();


        return ee;
    }
}
```