我来写常规的解法，却是费时间的11ms,mmp
```
public int findUnsortedSubarray(int[] nums) {
        int length = nums.length;
        int[] copyNums = Arrays.copyOf(nums, length);
        Arrays.sort(copyNums);
        int imin = 0, imax = 0;
        
        for (int i = 0; i < length; i++) {
            if (copyNums[i] != nums[i]){
                imin = i;
                break;
            }
        }

        for (int i = length - 1; i >= 0 ; i--) {
            if (copyNums[i] != nums[i]){
                imax = i + 1;
                break;
            }
        }

        return imax - imin;
    }
```
