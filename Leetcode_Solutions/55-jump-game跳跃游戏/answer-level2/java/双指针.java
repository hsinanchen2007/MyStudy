class Solution {
    public boolean canJump(int[] nums) {
        int start = 0;
        int end = 0;
        while(start <= end && end < nums.length) {
            if(start + nums[start] > end) end = start + nums[start];
            start++;
        }
        if(end >= nums.length - 1) return true;
        return false;
    }
}
end表示start位置能达到的最后的位置，遍历往后，若end能达到最后一个，返回true