思路和最高赞类似，简单记录下
```
class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        int n=nums.length;
        if(n==0)return new int[0];
        int[] res=new int[n-k+1];
        Deque<Integer> deque=new LinkedList<>();
        for(int i=0;i<n;i++){
            while(!deque.isEmpty()&&nums[i]>deque.peekLast())
                deque.pollLast();
            deque.addLast(nums[i]);
            if(i>=k&&deque.peekFirst()==nums[i-k])deque.pollFirst();
            if(i>=k-1)res[i-k+1]=deque.peekFirst();
        }
        return res;
    }
}
```
