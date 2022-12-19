
```java
class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        if(nums.length==0) return new int[]{};
        Deque<Integer> dq = new LinkedList<Integer>();
        int[] res = new int[nums.length-k+1];
        int p=0;
        for (int i=0; i<k; i++) {
            while (!dq.isEmpty() && nums[dq.peekLast()]<nums[i]) dq.pollLast();
            dq.offerLast(i);
        }
        for (int j=k; j<nums.length; j++) {
            res[p] = nums[dq.peekFirst()];
            p++;
            if (dq.peekFirst() <= j-k) dq.pollFirst();
            while (!dq.isEmpty() && nums[dq.peekLast()]<nums[j]) dq.pollLast();
            dq.offerLast(j);
        }
        res[p] = nums[dq.peekFirst()];

        return res;
    }
}
```