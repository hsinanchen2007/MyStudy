由于二分查找的先后顺序决定着一类数字（如很多相同数字）的查找先后，所以我使用两次二分查找，第一次先比较左边数组和target，第二次先比较右边数组和target。代码如下：
```
public int[] searchRange(int[] nums, int target) {
        int left = 0;
        int right = nums.length - 1;
        int mid = left + (right - left) / 2;
        int[] result = new int[]{-1,-1};
        if(nums.length == 0){
            return result;
        }
        if(nums.length == 1){
            if(nums[0] == target){
                result[0] = 0;
                result[1] = 0;
                return result;
            }
        }
        if(nums.length == 2){
            if(target == nums[0]&&target != nums[1]){
                result[0] = 0;
                result[1] = 0;
            }
            else if(target == nums[1]&&target != nums[0]){
                result[0] = 1;
                result[1] = 1;
            }
            else if(target == nums[0]&&nums[0] == nums[1]){
                result[0] = 0;
                result[1] = 1;
            }
            return result;
        }
        //找开始位置
        while(left < right - 2){
            if(target >= nums[left]&&target <= nums[mid]){
                right = mid;
            }
            else{
                left = mid;
            }
            mid = left + (right - left) / 2;
        }
        if(nums[left] == target){
            result[0] = left;
        }
        else if(nums[mid] == target){
            result[0] = mid;
        }
        else if(nums[right] == target){
            result[0] = right;
        }
        left = 0;
        right = nums.length - 1;
        mid = left + (right - left) / 2;
        //找结束位置
        while(left < right - 2){
            if(target <= nums[right]&&target >= nums[mid]){
                left = mid;
            }
            else{
                right = mid;
            }
            mid = left + (right - left) / 2;
        }
        if(nums[right] == target){
            result[1] = right;
        }
        else if(nums[mid] == target){
            result[1] = mid;
        }
        else if(nums[left] == target){
            result[1] = left;
        }
        return result;
    }
```

