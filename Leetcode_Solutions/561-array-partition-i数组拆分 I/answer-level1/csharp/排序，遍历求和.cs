```
public class Solution {
    public int ArrayPairSum(int[] nums) {
        if(nums.Length == 0){
            return 0;
        }
        Array.Sort(nums);
        int total = 0;
        for(int i = 0;i<nums.Length;){
            total += nums[i];
            i+=2;
        }

        return total;
    }
}
```