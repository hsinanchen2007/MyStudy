```java
class Solution {
    public int removeElement(int[] nums, int val) {
        if (nums.length <= 0) {
            return nums.length;
        }
        if (nums.length == 1) {
            return nums[0] == val ? 0 : 1;
        }

        int i = 0;
        while(i < nums.length && nums[i] != val) {
            ++i;
        }
        int j = i + 1;
        while(j < nums.length) {
            if (nums[j] == val) {
                ++j;
                continue;
            } else {
                nums[i] = nums[j];
                ++i; ++j;
            }
        }
        return i;
    }
}
```