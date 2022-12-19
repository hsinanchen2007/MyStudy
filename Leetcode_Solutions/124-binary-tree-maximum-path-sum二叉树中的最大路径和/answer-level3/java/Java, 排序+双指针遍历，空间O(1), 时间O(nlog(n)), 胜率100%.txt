```java
class Solution {
    public int longestConsecutive(int[] nums) {
        if(nums.length < 2) {
            return nums.length;
        }
        Arrays.sort(nums);
        int max = 1;
        int i =0, j=1;
        while(j<nums.length) {
            if(nums[j - 1] + 1 == nums[j] || nums[j - 1] == nums[j]) {
                max = Math.max(max, nums[j]-nums[i]+1);
            } else {
                i=j;
            }
            j++;
        }
        return max;
    }
}
```
