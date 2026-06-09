    // 将数组的下标和数组下标中对应的数都当作指针，快慢前进
    // 找入环点，入环点处指针值为重复的数（因为重复的值是有多个值指向它的，多对一的关系）
    class Solution {
        public int findDuplicate(int[] nums) {
            int slow = 0, fast = 0;
            do {
                slow = nums[slow];
                fast = nums[nums[fast]];
            }while(slow != fast);
            fast = 0;
            while(fast != slow) {
                fast = nums[fast];
                slow = nums[slow];
            }
            return slow;
        }
    }