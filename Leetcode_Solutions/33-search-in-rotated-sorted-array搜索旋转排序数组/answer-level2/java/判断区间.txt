### 解题思路
此处撰写解题思路
情况一：
   当nums[l]的值<=nums[mid]的时候，说明左边是有序的
        若目标值在nums[l]和nums[mid]之间的时候，确定到左边部分用二分查找，否则确定到右边部分
   当nums[l]的值>nums[mid]时，说明左边部分非有序，
        若目标值在nums[mid]和nums[r]之间的时候，在右边部分用二分查找，否则在左边部分用二分查找
时间复杂度：O(logn)
空间复杂度：O(1)
### 代码

```java
class Solution {
    public int search(int[] nums, int target) {
        int l=0,r=nums.length-1;
        int mid;
        if(nums==null ||nums.length==0)
            return -1;
        while(l<=r){
            mid=l+(r-l)/2;
            if(nums[mid]==target)
                return mid;
            if(nums[l]<=nums[mid]){
                if(target>=nums[l] && target<=nums[mid])
                    r=mid;
                else
                    l=mid+1;
            }
            else{
                if(target>nums[mid] && target<=nums[r])
                    l=mid;
                else
                    r=mid-1;
            }
        }
        return -1;
    }
}  
```