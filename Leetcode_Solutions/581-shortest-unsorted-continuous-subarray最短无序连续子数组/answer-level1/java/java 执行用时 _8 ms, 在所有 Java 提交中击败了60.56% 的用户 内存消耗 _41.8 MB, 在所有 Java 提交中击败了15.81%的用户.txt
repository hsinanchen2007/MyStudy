### 解题思路
先排序,再确定左右边界.确定边界的方法就是从左(右)遍历,取第一次时两个数组值不等的下标.

### 代码

```java
class Solution {
    public int findUnsortedSubarray(int[] nums) {
       int[] nums1=Arrays.copyOf(nums,nums.length);
       Arrays.sort(nums1);
       int i=0;
       int j=nums1.length-1;
        while(i<nums1.length)
        {
            if(nums1[i]==nums[i])
               i++;
            else
              break;
        }
        while(j>=0)
        {
            if(nums1[j]==nums[j])
               j--;
            else
              break;
        }
        if(i<=j)
          return j-i+1;
        else return 0;
    }
}
```