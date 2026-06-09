```
class Solution {
    public boolean containsDuplicate(int[] nums) {
        Arrays.sort(nums);
        int i = 0;
        while(i < nums.length - 1){
            if(nums[i] == nums[i + 1])//如果有相等元素，一定是连续的
                return true;
            else
                i++;
        }
        return false;
    }
}
```
