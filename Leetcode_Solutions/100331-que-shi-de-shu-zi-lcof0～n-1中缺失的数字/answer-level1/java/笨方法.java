class Solution {
    public int missingNumber(int[] nums) {
        int maxTotal = (nums.length + 1) * (nums.length) / 2;

        int currentTotal = 0;
        for (int a : nums) {
            currentTotal += a;
        }

        return maxTotal - currentTotal;
    }
}