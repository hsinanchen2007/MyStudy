两次for循环，第一次把数组挪到前方，第二次把后边的数都改成0
```
class Solution {
    public void moveZeroes(int[] nums) {
        int N = nums.length;
        int count = 0;
        for(int i = 0; i < N; i++) {
            if(nums[i] != 0) {
                nums[count] = nums[i];
                count++;
            }
        }
        for(int i = count; i < N; i++) {
            nums[i] = 0;
        }
    }
}
```
