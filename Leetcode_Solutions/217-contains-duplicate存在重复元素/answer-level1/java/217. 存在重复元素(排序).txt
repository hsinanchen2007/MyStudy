```
class Solution {
    public boolean containsDuplicate(int[] nums) {
        int i;

        Arrays.sort(nums);
        for(i = 1; i < nums.length; i++)
            if(nums[i] == nums[i-1])
                return true;
        return false;
    }
}
```
