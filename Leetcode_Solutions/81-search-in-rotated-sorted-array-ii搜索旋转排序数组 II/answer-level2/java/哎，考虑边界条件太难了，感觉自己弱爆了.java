### 解题思路
先找出旋转的位置，然后用二分法直接解决
### 代码

```java
class Solution {
    public boolean search(int[] nums, int target) {
        int left=0,right=nums.length-1;
        int mid=0;
        if(nums.length==0)
            return false;
        //查找mid位置
        while(mid<right && nums[mid]<=nums[++mid]) ;
        if(target<nums[0])
            left=mid;
        else
            right=mid--;
        //二分解决
        while(left<=right){
            mid=(left+right)/2;
            if(nums[mid]==target)
                return true;
            if(nums[mid]<target)
                left=mid+1;
            else
                right=mid-1;
        }
        return false;
        
    }
}
```