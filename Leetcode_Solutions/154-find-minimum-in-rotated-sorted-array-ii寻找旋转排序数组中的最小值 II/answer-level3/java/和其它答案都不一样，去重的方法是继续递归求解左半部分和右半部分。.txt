### 解题思路
和其它答案都不一样，去重的方法是继续递归求解左半部分和右半部分。如果不存在duplicated，那么就是O(logn)。如果所有数都一样，那么就是O(N)。并且我用的target是定值就是第一个元素。

### 代码

```java
class Solution {
    public int findMin(int[] nums) {
        
        if(nums.length == 1)
        {
            return nums[0];
        }
        
        return binarySearch(nums, 0, nums.length, nums[0]);
    }
    
    public int binarySearch(int[] nums, int start , int end, int target)
    {
        if(start>=nums.length)
        {
            return Integer.MAX_VALUE;
        }
        
        
        int l = start;
        int r = end;
        
        while(l<r)
        {
            int m = l + (r - l) /2;
            
                    
            if(nums[m] < target)
            {
                r = m;
            }
            else if (nums[m] > target)
            {
                l = m + 1;
            }
            else
            {
                if(l==m)
                {
                    l = m +1;
                }
                else
                {
                    return Math.min(binarySearch(nums, l , m, target),
                                   binarySearch(nums, m + 1 , r, target));
                }
            }
        }
        
        
        if(l==nums.length)
        {
            return nums[start];
        }
        else
        {
            return nums[l];
        }
    }
    
}
```