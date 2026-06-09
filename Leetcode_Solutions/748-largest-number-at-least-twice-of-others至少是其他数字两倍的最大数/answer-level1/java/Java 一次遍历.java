```
class Solution {
    public int dominantIndex(int[] nums) {
        
        if (nums.length == 1) {
            return 0;
        }
        
        int maxIndex = nums[0] > nums[1] ? 0 : 1;
        int preMaxIndex = nums[0] > nums[1] ? 1 : 0;
        int dominantIndex = -1;
        for(int i = 2; i < nums.length; i++) {
            if (nums[i] > nums[maxIndex]) {
                preMaxIndex = maxIndex;
                maxIndex = i;
            } else if (nums[i] > nums[preMaxIndex]) {
                preMaxIndex = i;
            }
        }
        
        if (nums[maxIndex] >= nums[preMaxIndex] * 2) {
            dominantIndex = maxIndex;
        }
        
        return dominantIndex;
    }
}
```

思路就是找到最大的前两个数。然后比较第一大的数是否至少是第二大的数的两倍