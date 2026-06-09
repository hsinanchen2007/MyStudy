### 解题思路
比较大小

### 代码

```java
class Solution {
    public int searchInsert(int[] nums, int target) {
        int n = nums.length;
        int i;
        for(i=0;i<n;i++){
            if(nums[i]>=target)
                break;
        }
        return i;
    }
}
```