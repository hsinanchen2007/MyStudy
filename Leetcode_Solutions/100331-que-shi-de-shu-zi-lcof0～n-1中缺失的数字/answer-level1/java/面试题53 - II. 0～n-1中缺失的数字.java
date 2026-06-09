class Solution {
    // 因为数据有序，如果没有缺少的数字，那么nums[i] = i
    // 通过二分法，如果nums[mid] = mid,表明前半段正常，后半段缺少数字，此时left = mid + 1,right不变
    // 对后半段继续进行同样的处理，当left = right时结束循环
    public int missingNumber(int[] nums) {
        if (nums[0] != 0) {
            return 0;
        }
        int left = 0;
        int right = nums.length - 1;
        int mid = 0;
        while (left < right) {
            mid = (left + right) /2;
            if (nums[mid] != mid) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        // 如果循环完之后中间没有缺少数字，返回最大元素+1
        if (nums[left] == left) {
            left += 1;
        }
        return left;
    }
}