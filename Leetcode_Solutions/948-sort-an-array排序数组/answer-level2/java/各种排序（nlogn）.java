快速排序：
```
class Solution {
   public int[] sortArray(int[] nums) {
        if(nums == null || nums.length == 0){
            return nums;
        }
        quickSort(nums, 0, nums.length - 1);
        return nums;
    }

    public void quickSort(int[] nums, int start, int end){
        if(start >= end){
            return;
        }
        int privo = nums[(start + end) / 2];
        int left = start, right = end;
        while(left <= right){
            while(left <= right && nums[left] < privo){
                left++;
            }
            while(left <= right && nums[right] > privo){
                right--;
            }
            if(left <= right){
                int temp = nums[left];
                nums[left] = nums[right];
                nums[right] = temp;
                left++;
                right--;
            }
        }
        
        quickSort(nums, start, right);
        quickSort(nums, left, end);
    }
}
```
归并排序：
```
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

        for (index = start; index <= end; index++) {
            nums[index] = temp[index];
        }
    }
}
```
