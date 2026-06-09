### 解题思路
我知道这题肯定用优先队列
自己手写个归并排序 加强理解

### 代码

```java
class Solution {
    public int findKthLargest(int[] nums, int k) {
        
        //bad-case
        if (nums.length == 0) {
            return 0;
        }

        //归并排序
        mergeSort(nums, 0, nums.length - 1);

        //debug 
        /*for (int i = 0; i < nums.length; i ++) {
            System.out.println(nums[i]);
        }*/
        int count = 1;
        //循环一遍数组
        for (int i = 1; i < nums.length; i++) {
            //debug
            //System.out.println(nums[i]);
            //if (nums[i] != nums[i-1]) {
                count++;
                if (count == k) {
                    return nums[i];
                }
            //}
        }

        return nums[0];
    }

    //自顶向下归并
    private void mergeSort(int[] nums, int left, int right) {
        if (left >= right) {
            return;
        }
        int mid = (left + right) >>> 1;
        //区分左区间
        mergeSort(nums, left, mid);
        //区分右区间
        mergeSort(nums, mid + 1, right);
        //归并数组
        merge(nums, left, mid, right);
    }

    //两路归并 - 两个有序数组归并 - 自顶向下
    private void merge(int[] nums, int left, int mid, int right) {
        
        //临时辅助数组
        int[]  temp = new int[nums.length];

        //临时数组的索引值
        int k = left;
        
        //遍历的初始指针1
        int p1 = left;

        //遍历的初始指针2
        int p2 = mid + 1;

        //开始归并排序
        while (p1 <= mid && p2 <= right) {
            if (nums[p1] > nums[p2]) {
                temp[k++] = nums[p1];
                p1++;
            } else {
                temp[k++] = nums[p2];
                p2++;
            }
        }

        //若此时尚未归并完
        //p1未完
        while (p1 <= mid)   temp[k++] = nums[p1++];
        //p2未完
        while (p2 <= right) temp[k++] = nums[p2++];

        //临时数组回填
        for (int i = left; i < right+1; i++) {
            nums[i] = temp[i];
        }
    }
}
```