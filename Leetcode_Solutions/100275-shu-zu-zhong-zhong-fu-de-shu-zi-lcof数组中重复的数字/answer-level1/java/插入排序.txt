思路：
按照插入排序的方式，插入的时候，遇到两个相等就直接返回
```
class Solution {
    public int findRepeatNumber(int[] nums) {
        if (nums == null || nums.length == 0) {
            return 0;
        } else if (nums.length <= 2) {
            return nums[0];
        }

        for (int i = 1; i < nums.length; i++) {
            if (nums[i] < nums[i - 1]) {
                //如果第i个数大于前一个数就不用判断了,因为前面都是有序数列,大于前一个数肯定比前面所有数都大,否则的话把这个数拿出来也就是赋值给temp,然后依次与前面的数比较,如果比前一个数小就让前一个数往后挪一位直到找到比temp小的位置放进去
                int temp = nums[i];
                int f = i;
                for (; f >= 1 && nums[f - 1] > temp; f--) {
                    nums[f] = nums[f - 1];

                }
                nums[f] = temp;
                if (f >= 1 && nums[f] == nums[f - 1]) {
                    return nums[f];
                }
            }
            if (nums[i] == nums[i - 1]) {
                return nums[i];
            }
        }
        return nums[0];
    }
}
```
