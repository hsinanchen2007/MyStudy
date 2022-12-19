### 解题思路
要理解二分法，旋转后肯定是两部分的连续递增，折半后肯定有一部分是连续的。

### 代码

```java
class Solution {
    public int search(int[] nums, int target) {
        int left = 0;
        int right = nums.length-1;
        while(left<=right){
            int mid = left+(right-left)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[left]<=nums[mid]){//说明[left,mid]连续递增
                if(target>=nums[left]&&target<nums[mid])//target在[left,mid)之间
                    right = mid-1;//缩小右边界
                else
                    left = mid+1;//target在(mid,right]之间
            }
            else if(nums[left]>nums[mid]){//[mid,right]连续递增
                if(target>nums[mid]&&target<=nums[right])//target在(mid,right]之间
                    left = mid+1;//缩小左边界
                else
                    right = mid-1;//target在[left,mid)之间
            }
        }
        return -1;
    }
}
```