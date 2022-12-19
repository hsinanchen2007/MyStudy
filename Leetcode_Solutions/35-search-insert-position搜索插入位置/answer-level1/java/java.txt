### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int searchInsert(int[] nums, int target) {
        int c = Arrays.binarySearch(nums,target);
        if (c > 0) return c;
        else
            for (int i = 0; i < nums.length; i++) {
                if (nums[i] >= target){
                    c = i;
                    break;
                }
                if (i == nums.length - 1)
                {
                    c = nums.length ;
                    return c;
                }
            }
            return c;
    }
}
```