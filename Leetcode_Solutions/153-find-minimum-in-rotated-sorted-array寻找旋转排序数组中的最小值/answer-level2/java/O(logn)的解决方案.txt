### 解题思路
思路和二分查找某个值的思路一样，只不过某个值变成了出现串序的位置。

### 代码

```java
class Solution {
    private int finding(int[] nums,int begin,int end)
    {
        //[begin,end]已经有序，则返回最小的即可
        if(nums[begin]<nums[end])
            return nums[begin];
        //判断一个数的情况
        if(begin==end)
            return nums[begin];
        //判断两个数的情况
        if(begin+1==end)
            return Math.min(nums[begin],nums[end]);

        int mid=begin+(end-begin)/2;
        //取mid的情况：nums[mid]小于其左右两边的数
        if(nums[mid]<nums[mid-1]&&nums[mid]<nums[mid+1])
            return nums[mid];
        //关键：nums[mid]>nums[begin]表明左边[begin,mid]已经有序，我们要找的是最小值，也就是串序的位置。
        return nums[mid]>nums[begin]?finding(nums,mid+1,end):finding(nums,begin,mid-1);
    }
    public int findMin(int[] nums) {
        return finding(nums,0,nums.length-1);
    }
}
```