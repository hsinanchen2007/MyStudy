

```java []
class Solution {
    public void wiggleSort(int[] nums) {
        Arrays.sort(nums);
        int length = nums.length;
        int insetIndex = 0; //记录将要插入的数组下标
        int sourceInsetIndex = (length % 2 == 0) ? length / 2 - 1 : length / 2; //记录排序后较小部分最大的值下标
        while (sourceInsetIndex > insetIndex) {
            //较小部分最大值插入排序
            insert(nums, insetIndex, sourceInsetIndex);
            insetIndex++; //将要插入的数组下标后移
            //较大部分最大值插入排序
            insert(nums, insetIndex, length - 1);
            insetIndex++;//将要插入的数组下标后移
            sourceInsetIndex++;//较小部分最大的值下标由于较大部分最大值插入而产生的后移
        }
    }
    // 插入排序
    private void insert(int[] nums, int insetIndex, int sourceInsetIndex) {
        int temp = nums[sourceInsetIndex];
        if (sourceInsetIndex - insetIndex > 0)
            System.arraycopy(nums, insetIndex, nums, insetIndex + 1, sourceInsetIndex - insetIndex);
        nums[insetIndex] = temp;
    }
}
```

