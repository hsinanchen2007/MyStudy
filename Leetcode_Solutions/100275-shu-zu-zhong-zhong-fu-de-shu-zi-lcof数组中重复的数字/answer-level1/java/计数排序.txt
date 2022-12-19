### 解题思路
桶排序思想下的计数排序，时间复杂度和空间复杂度都比较低，代码也很简洁

### 代码

```java
class Solution {
    public int findRepeatNumber(int[] nums) {
        int[] arr = new int[nums.length];
        for(int i = 0; i < nums.length; i++) {
            arr[nums[i]]++;
            if(arr[nums[i]] > 1) {
                return nums[i];
            }
        }
        return 0;
    }
}
```