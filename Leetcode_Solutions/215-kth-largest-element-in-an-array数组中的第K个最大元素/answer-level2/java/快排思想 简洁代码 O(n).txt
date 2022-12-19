```
class Solution {
    public int findKthLargest(int[] nums, int k) {
        return partation(nums,0,nums.length-1,k);
        
    }
   
    int partation(int[] nums, int start, int end, int k) {
        int counter = start, pivot = end;
        for (int i = start; i < end; i++) {
            if (nums[i] > nums[pivot]) {
                int tmp = nums[i];
                nums[i] = nums[counter];
                nums[counter] = tmp;
                counter++;
            }
        }
        int tmp = nums[counter];
        nums[counter] = nums[pivot];
        nums[pivot] = tmp;

        if (counter == k-1) {
            return nums[counter];
        } else if (counter < k-1) {
            return partation(nums, counter + 1, end, k);
        } else {
            return partation(nums, start, counter - 1, k);
        }
    }
}
```
有疑问可留言。
