和其他三数之和相同，重点在于count的更新  count = count + right - left;

class Solution {
    public int threeSumSmaller(int[] nums, int target) {
        Arrays.sort(nums);
        int length = nums.length;
        
        int count = 0;
        
        for (int i = 0; i < length; i++) {
            int left = i + 1;
            int right = length - 1;
            
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum >= target) {
                    right--;
                } else {
                    count = count + right - left;
                    left++;
                }
            }
        }
        return count;
    }
}