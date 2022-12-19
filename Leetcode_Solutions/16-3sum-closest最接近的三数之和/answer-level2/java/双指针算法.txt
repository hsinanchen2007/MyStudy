```
class Solution {
    public int threeSumClosest(int[] nums, int target) {
        if(nums == null || nums.length == 0){
            return 0;
        }

        Arrays.sort(nums);

        int diff = Integer.MAX_VALUE;
        int res = 0;

        for (int i = 0; i < nums.length; i++) {
            int left = 0, right = i - 1;
            while(left < right){
                int sum = nums[left] + nums[right] + nums[i];
                if(sum < target){
                    if(target - sum < diff){
                        diff = target - sum;
                        res = sum;
                    }
                    left++;
                }else{
                    if(sum - target < diff){
                        diff = sum - target;
                        res = sum;
                    }
                    right--;
                }
            }
        }
        return res;
    }
}
```
