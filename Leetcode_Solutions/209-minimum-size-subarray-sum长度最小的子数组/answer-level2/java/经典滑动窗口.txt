
```
class Solution {
    public int minSubArrayLen(int s, int[] nums) {
        int res = nums.length+1; //记录全局最小
        int curSum = 0; /*记录滑动窗口中的元素和*/
        for(int l=0,r=0;r<nums.length;r++){ /*[l,r]框定了窗口左右边界*/
            curSum+=nums[r]; /*nums[r]进入窗口，更新curSum的值*/
            if(curSum>=s){ /*如果窗口内元素和curSum>=s*/
                while(curSum>=s) /*在curSum>=s的条件下，尝试将左边界l向右移，直到curSum<s*/
                    curSum-=nums[l++]; /窗口左边界l右移一格，同时curSum减去nums[l]

                /*退出上面的while后，窗口范围为[l,r]
                此时的窗口长度为r-l+1,窗口内元素和curSum<s，
                但[l-1,r]内的元素和却是>=s的
                更新res即可，res=min(res,(r-l+1)+1)
                */
                res=Math.min(res,(r-l+1)+1);
            }
        }
        
        return res>nums.length?0:res;
    }
}
```
