![二分法.PNG](https://pic.leetcode-cn.com/9651992fb3d10f7b62caf25485ad07fa50ab824bb6486cc1c31f1fadcc750526-%E4%BA%8C%E5%88%86%E6%B3%95.PNG)

class Solution {
    public int searchInsert(int[] nums, int target) {
        int head = 0;
        int end = nums.length - 1;
        int middle = (head + end)/2;
        //先判断一遍边界，顺便把数组长度为1和2的情况解决了
        if(target > nums[end]){
            return end + 1;
        }else if(target < nums[head]){
            return 0;
        }

        if(target == nums[head]){
            return  head;
        }else if(target == nums[end]){
            return end;
        }

        //二分法解决head < end - 1时的情况
        while(head < end - 1){
            if(target > nums[middle]){
                head = middle;
            }else if (target < nums[middle]){
                end = middle;
            }else {
                return middle;
            }
            middle = (head + end)/2;
        }
        //走完while表示没有匹配到数值
        return end;//把数值插入到head后一位

    }
}