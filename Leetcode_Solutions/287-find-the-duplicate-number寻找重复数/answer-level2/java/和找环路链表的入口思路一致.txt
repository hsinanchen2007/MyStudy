执行用时 :0 ms, 在所有 java 提交中击败了100.00% 的用户
内存消耗 :37.4 MB, 在所有 java 提交中击败了93.77%的用户
```
class Solution {
    public int findDuplicate(int[] nums) {
        if(nums == null || nums.length < 1)
            return -1;
        int slow = nums[0];
        int fast = nums[nums[0]];
        while(slow != fast){
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        slow = 0;
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
}
```
