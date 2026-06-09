```
class Solution {
    public void sortColors(int[] nums) {
        int a = 0,j=0,k=nums.length - 1;

        while (true){
            if (nums[j] == 2) {
                if (nums[k] < 2) {
                    nums[j] = nums[k];
                    nums[k] = 2;
                    k --;
                } else {
                    k--;
                }
            } else if(nums[j] == 1) {
                j++;
            } else if (nums[j] == 0) {
                if (nums[a] == 1) {
                    nums[a] = 0;
                    nums[j] = 1;
                    a++;
                    j++;
                } else {
                    a++;
                    j++;
                }
            }
            if (j > k) {
                break;
            }
        }
    }
}
```
