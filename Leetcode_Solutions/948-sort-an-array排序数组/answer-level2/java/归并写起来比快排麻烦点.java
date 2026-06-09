### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
   public int[] sortArray(int[] nums) {
        if(nums == null || nums.length == 0){
            return nums;
        }
        mergeSort(nums, 0, nums.length - 1, new int[nums.length]);
        return nums;
    }

    public void mergeSort(int[] nums, int start, int end, int[] temp){
        if(start >= end){
            return;
        }
        int mid = (start + end) / 2;
        mergeSort(nums, start, mid, temp);
        mergeSort(nums, mid + 1, end, temp);
        merge(nums, start, end, temp, mid);
    }

    public void merge(int[] nums, int start, int end, int[] temp, int mid){
        int left = start, right = mid + 1;
        int index = start;
        while(left <= mid && right <= end){
            if(nums[left] <= nums[right]){
                temp[index++] = nums[left++];
            }else{
                temp[index++] = nums[right++];
            }
        }
        
        while(left <= mid){
            temp[index++] = nums[left++];
        }
        
        while(right <= end){
            temp[index++] = nums[right++];
        }


        for (int i = start; i <= end; i++) {
            nums[i] = temp[i];
        }
    }
}
```