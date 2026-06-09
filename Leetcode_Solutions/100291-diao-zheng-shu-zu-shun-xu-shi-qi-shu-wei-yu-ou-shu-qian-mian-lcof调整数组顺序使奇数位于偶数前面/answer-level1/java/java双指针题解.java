利用快速排序的思想，一个指针left从前面开始找偶数，一个指针right从后面开始找奇数，然后调换两个位置的数字，直到
left >= right，此时所有的奇数都在前面，所有的偶数都在后面

```
class Solution {
    public int[] exchange(int[] nums) {
        int left = 0;
        int right = nums.length - 1;
        while(left < right){
            while(left < nums.length - 1 && nums[left] % 2 == 1){
                left++;
            }

            while(right > 0 && nums[right] % 2 == 0){
                right--;
            }

            if(left < right){
                int temp = nums[left];
                nums[left++] = nums[right];
                nums[right--] = temp;
            }
        }
        return nums;
    }
}
```
