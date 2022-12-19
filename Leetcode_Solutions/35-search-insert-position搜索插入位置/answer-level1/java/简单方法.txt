### 解题思路
遍历数组，当找到target或没有找到target但找到第一个大于target的元素时，这时的下标i即为所求。另外还要考虑target大于数组中所有元素的情况。

### 代码

```java
class Solution {
    public int searchInsert(int[] nums, int target) {
        for(int i=0;i<nums.length;i++)
        {
            if(nums[i]==target||nums[i]>target)
            {
                return i;
            }
        }
        if(target>nums[nums.length-1]) return nums.length;
        return 0;
    }
}
```