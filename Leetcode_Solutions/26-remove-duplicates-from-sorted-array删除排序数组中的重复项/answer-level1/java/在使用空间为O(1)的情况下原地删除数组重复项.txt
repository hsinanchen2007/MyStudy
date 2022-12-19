解题思路：并没有采用双指针的方法，而是通过遍历数组，依次将不同的值交换到前面。设置两个变量：index、count。index用于纪录下一次保存不同值的数组下标，count用于纪录数组中不重复元素的个数。这种方法的时间效率为O(n)，提交执行用时1ms
解法如下：
class Solution {
    public int removeDuplicates(int[] nums) {
        int count=1;
        int index=0;
        for(int i=0;i<nums.length-1;i++)
        {
            if(nums[i]==nums[i+1])
            {
                continue;
            }
            else
            {
                index++;
                nums[index]=nums[i+1];
                count++;
            }
        }
        
        return count;
    }
}