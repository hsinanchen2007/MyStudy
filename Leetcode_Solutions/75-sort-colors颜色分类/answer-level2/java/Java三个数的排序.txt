思路很简单，2和前面不是2的数交换，0和后面不是0的数交换。
```
class Solution {
    public void sortColors(int[] nums) {
        if (nums.length == 0) return;
        int indexOfTwo = nums.length - 1;
        for (int i = 0; i < indexOfTwo; i++) {

            if (nums[i] == 2) {
                while (indexOfTwo >= 0 && nums[indexOfTwo] == 2) {
                    indexOfTwo--;
                }
                if (i < indexOfTwo) {
                    nums[i] ^= nums[indexOfTwo];
                    nums[indexOfTwo] ^= nums[i];
                    nums[i] ^= nums[indexOfTwo];
                }
            }
        }
        int indexOfZero = 0;
        for (int i = nums.length - 1; i >= indexOfZero; i--) {
            if (nums[i] == 0) {
                while (indexOfZero < nums.length && nums[indexOfZero] == 0) {
                    indexOfZero++;
                }
                if (i > indexOfZero) {
                    nums[i] ^= nums[indexOfZero];
                    nums[indexOfZero] ^= nums[i];
                    nums[i] ^= nums[indexOfZero];
                }
            }
        }
    }
}
```