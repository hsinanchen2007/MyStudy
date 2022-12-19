```
class Solution {

    public int findKthLargest(int[] nums, int k) {
        // 使用插入排序算法进行排序，按照从大到小进行排序
        int length = nums.length;
        for (int i = 1; i < length; i++) {
            // 此次待插入的数组中数据
            int curInsert = nums[i];
            int j = i - 1;
            while (j >= 0 && curInsert > nums[j]) {
                nums[j + 1] = nums[j];
                j--;
            }
            nums[j + 1] = curInsert;
        }
        return nums[k - 1];
    }
}
```