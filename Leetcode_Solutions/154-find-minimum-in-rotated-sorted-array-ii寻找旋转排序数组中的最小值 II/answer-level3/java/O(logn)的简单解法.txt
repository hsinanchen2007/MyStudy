### 解题思路
在153题的基础上，增加判断重复的条件。
基础思想还是：
取中点值n[mid]，与最右的值n[right]比较，
    1. 若n[mid]==n[right],right--，直到不相等.之后right有可能小于mid，调整right=mid，程序继续;
    2. 若n[mid]>n[right]，则说明[mid+1,right]范围无序，left=mid+1;
        否则right=mid;
### 代码

```java
class Solution {
    public int findMin(int[] nums) {
        int left=0,right=nums.length-1;
        while(left<right)
        {
            int mid=left+(right-left)/2;
            while(right>=0&&nums[mid]==nums[right])right--;
            if(right<mid)
            {
                right=mid;
                continue;
            }
            if(nums[mid]>nums[right])
                left=mid+1;
            else 
                right=mid;
        }
        return nums[left];
    }
}
```