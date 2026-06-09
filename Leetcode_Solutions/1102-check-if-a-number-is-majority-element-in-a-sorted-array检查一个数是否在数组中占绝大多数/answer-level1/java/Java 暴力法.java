```
class Solution {
    public boolean isMajorityElement(int[] nums, int target) {
        int times = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == target) {
                times++;
            }
        }
        return times > nums.length / 2 ? true : false;
    }
}
```
