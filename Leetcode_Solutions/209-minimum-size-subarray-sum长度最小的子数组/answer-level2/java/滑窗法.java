[leetcode209](https://leetcode-cn.com/problems/minimum-size-subarray-sum/)

* 滑窗法：首先建立一个滑窗，滑窗大小等于目前已知结果减一；
  * 滑窗向右移动一格，若其内数字之和小于目标值，继续移动。
  * 滑窗向右移动一格，若其内数字之和大于等于目标值，则滑窗左侧端点++（不可能让滑窗从右端点收缩，因为这样会让滑窗之和小于上一次滑窗之和了），滑窗大小减小。
* 此题也可以利用暴力法，但是要及时剪枝处理。

```java
class Solution {
    public int minSubArrayLen(int s, int[] nums) {
        int n = nums.length;
        int start=0,end =0; //不包含end 
        int count =0;
        while( end < n){
            count+=nums[end];
            end++;
            if(count >= s) break;
        }
        if(end == n && count < s) return 0;
        while(end < n || count>=s){  //最后一次若是end==n,但是count>=s，就需要在进行处理。
            while(count >= s && start<end){  //start==end 说明有一个数字已经大于s了
                count-=nums[start];
                start++;
            }
            if(start == end) return 1;
            while(count < s && end < n){
                count+=nums[end];
                count-=nums[start];
                end++;
                start++;
            }
        }
        return end-start+1;  //滑窗总是小于当前这数字。
    }  
}
```

