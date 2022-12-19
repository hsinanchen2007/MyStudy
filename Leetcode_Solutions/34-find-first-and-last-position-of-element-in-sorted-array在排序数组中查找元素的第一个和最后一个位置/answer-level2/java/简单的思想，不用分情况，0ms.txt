很简单的想法，二分查找找到所有的目标值，下标最小为左值，下标最大为右值
```
class Solution {
    int min = Integer.MAX_VALUE;
    int max = -1;
    public int[] searchRange(int[] nums, int target) {
        
        int[] result = new int[2];
        result[0] = -1;
        result[1] = -1;

        if(nums.length == 0)
            return result;
            
        partition(nums, 0, nums.length-1, target);
        if(min == nums.length || max == -1){
            return result;
        }
        result[0] = min;
        result[1] = max;
        return result;
            
    }

    public void partition(int[] nums, int left, int right, int target){
        if(left == right){
            if(nums[left] == target){
                if(left < min)
                    min = left;
                if(left > max)
                    max = left;
            }
            return;
        }


        int n = (right + left)/2;
        if(target >= nums[n+1])
            partition(nums, n+1, right, target);
        if(target <= nums[n])
            partition(nums, left, n, target);

    }
}
```
