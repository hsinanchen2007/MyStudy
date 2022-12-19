### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int search(int[] nums, int target) {
        int left=0;
        int right=nums.length-1;
        while(left<right)
        {
            int mid=left+(right-left+1)/2;
            if(nums[mid]<target)
            {
                left=mid;
            }
            else
            {
                right=mid-1;
            }
        }
        int i=left;
        int count=0;
        while(i<nums.length&&nums[i]<=target)
        {
            if(nums[i]==target)
            count++;
            i++;
        }
        return count;
    }
}
```