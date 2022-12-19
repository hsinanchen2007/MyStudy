### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int findMin(int[] nums) {
        int len=nums.length;
        for(int i=1;i<len;i++)
        {
            if(nums[i]<nums[i-1])
                return nums[i];
        }
        return nums[0];
    }
}
```