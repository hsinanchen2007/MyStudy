当看到“**连续**子数组”这一题眼时，就应该想到双指针滑动窗口。时间复杂度O(N)
滑动窗口：在一次遍历数组的过程中，我们若找到了一个符合条件的**连续**子数组，可能该子数组减去左边界之后仍然符合条件。例如:[1,1,1,6],s=6,那么减去三次左边界后，还是符合限定条件。但res.length应更新为1。
思考另一个的情况，我们找到的连续子数组是[1,1,1,6],s=11,此时记录len,左窗口右滑后发现不符条件，继续向后遍历。若右边界6之后是正整数5，我们这一次得到的连续子数组是[1,1,6,5],sum=13 >= s,长度为4,但左边界仍可以缩短两次。
```
class Solution {
    public int minSubArrayLen(int s, int[] nums) {
        if(nums == null)
            return 0;
        int res = Integer.MAX_VALUE;
        //双指针记录左右窗口
        int left = 0;
        int right = 0;
        int sum = 0;
        int len = 0;
        //右窗口滑到底，只遍历一次数组
        while(right < nums.length){
            sum+=nums[right];
            while(left <= right && sum >= s){
                //注意res用来记录长度，应该+1
                res = res < right-left+1 ? res:right-left+1;
                //左窗口向右滑动
                sum-=nums[left];
                left++;
            }
            right++;//右窗口滑动顺序也可以放在第二个while之上，更改循环条件即可。
        }
        if(res == Integer.MAX_VALUE)
            res = 0;
        return res;
    }
}
```
