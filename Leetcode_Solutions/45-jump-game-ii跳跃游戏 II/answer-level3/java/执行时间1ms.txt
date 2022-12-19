```
class Solution {
    public int jump(int[] nums) {
        if (nums.length == 1) {
            return 0;
        }
        int count= 0;
        for (int i=0; i<nums.length;) {
            count++;
            int jump = nums[i];
            if (i+jump >= nums.length-1) {
                break;
            }
            if (jump == 1) {
                i++;
                continue;
            }
            int max = nums[i+1];
            int plus = 1;
            for (int j=2; j<=jump; j++) {
                if (max < (nums[i+j] + j - 1)) {
                    plus = j;
                    max = nums[i+j] + j - 1;
                }
            }
            i += plus;
        }
        return count;
    }
}
```
