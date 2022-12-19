### 解题思路
快速排序的思想大家应该都知道，不知道的也可以很方便查到，就不赘述了
这里多嘴一句，为什么右指针要先走？我的想法是，如果左指针先走的话，那么它一定会在大于基准数的地方停下，如果右指针这时与左指针相遇了，那么该位置与基准数交换，原基准数的位置变得比基准数还大，排序就出问题了。

### 代码

```java
class Solution {
    public int[] sortArray(int[] nums) {
        sort(nums, 0, nums.length-1);
        return nums;
    }

    private void sort(int[] nums, int start, int end){
        if(start >= end) return;

        int j = quickSort(nums, start, end);
        sort(nums, start, j-1);
        sort(nums, j+1, end);
    }

    private int quickSort(int[] nums, int l, int r){
        int base = nums[l];
        int i = l;
        int j = r+1;

        while(true){
            while(less(base, nums[--j]) && j != l);
            while(less(nums[++i], base) && i != r);
            if(i >= j) break;
            swap(nums, i, j);
        }
        swap(nums, l, j);
        return j;
    }

    private boolean less(int a, int b){
        return a <= b;
    }

    private void swap(int[] nums, int a, int b){
        int temp = nums[a];
        nums[a] = nums[b];
        nums[b] = temp;
    }
}
```