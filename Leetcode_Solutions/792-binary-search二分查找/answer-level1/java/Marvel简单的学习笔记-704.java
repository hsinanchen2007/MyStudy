### 解题思路
基本得不能再基本的二分查找题。

### 代码

```java
class Solution {
    public int search(int[] nums, int target) {
        int lo=0,hi=nums.length-1;
        while(lo<=hi)
        {
            int mid=lo+(hi-lo)/2;
            if(nums[mid]>target)      hi=mid-1;
            else if(nums[mid]<target) lo=mid+1;
            else                return mid;
        }
        return -1;
    }
}
```