### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int search(int[] nums, int target) {
    var left=0;
    var right=nums.length-1;
    while(left<=right)
    {
        int mid=(left+right)/2;
        if(nums[mid]==target)return mid;
        else if(nums[mid]>target){if(nums[left]>target&&nums[mid]>nums[right])left=mid+1;else right=mid-1;}
        else {if(target>nums[right]&&nums[mid]<nums[left])right=mid-1;else left=mid+1;}
    }
    return -1;
    }
}
```