### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        if(nums==null||nums.length<k||k==0){
            return new int[0];
        }
        int l=nums.length;
        int[] res=new int[l-k+1];
        Deque<Integer> q=new LinkedList<>();//双端队列
        for(int i=0;i<l;i++){
            while(!q.isEmpty()&&nums[q.getLast()]<nums[i]){//队列头部为窗口内的最大
                                                           //元素
                q.removeLast();
            }
            q.addLast(i);
            if(q.getFirst()==i-k){
                q.removeFirst();
            }
            if(i>=k-1){
                res[i-k+1]=nums[q.getFirst()];
            }
        }
        return res;
    }
}
```