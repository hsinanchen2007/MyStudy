```
class Solution {
    //方法1：分各种情况讨论
    public int search(int[] nums, int target) {
        if(nums == null) return -1;
        int l = 0;
        int r = nums.length - 1;
        int mid = 0;
        
        while(l <= r){
            mid = l + ((r - l) >> 1);
            if(nums[mid] == target){
                return mid;
            }
            
            if(target > nums[mid]){//此时需要去找比nums[mid]大的数
                
                if(nums[r] < nums[mid]){//旋转点在右边,所以l ~ mid - 1也都会小于target,所以只用去右边
                    l = mid + 1;
                }else if(nums[r] > nums[mid]){//旋转点在左边
                    //所以此时需要判断是去右边还是左边
                    if(target > nums[r]){
                        r = mid - 1;
                    }else if(target < nums[r]){
                        l = mid + 1;
                    }else if(target == nums[r]){
                        return r;
                    }
                }else if(nums[mid] == nums[r]){//说明此时l,r,mid三点重合，范围内只剩下一个元素，并且还不是target了，直接返回-1
                    return -1;
                }
            }else if(target < nums[mid]){//此时需要去找比nums[mid]小的数
                
                if(nums[r] < nums[mid]){//旋转点在右边
                    if(target < nums[r]){
                        l = mid + 1;
                    }else if(target > nums[r]){
                        r = mid - 1;
                    }else if(target == nums[r]){
                        return r;
                    }
                }else if(nums[r] > nums[mid]){//旋转点在左边
                    r = mid - 1;
                }else if(nums[mid] == nums[r]){//说明此时l,r,mid三点重合，范围内只剩下一个元素，并且还不是target了，直接返回-1
                    return -1;
                }
                
            }
        }
        return -1;
    }

    //方法2：根据有序部分锁定l和r的范围
    public int search(int[] nums, int target) {
        if(nums == null) {
            return -1;
        }
        
        int l = 0;
        int r = nums.length - 1;
        int mid;
        while(l <= r){
            mid = l + ((r - l) >> 1);
            
            if(nums[mid] == target){
                return mid;
            }else if(nums[mid] < nums[r]){//说明右半部分是有序的
                if(target > nums[mid] && target <= nums[r]){
                    l = mid + 1;
                }else {
                    r = mid - 1;
                }
            }else {//nums[mid] >= nums[l]
                if(target < nums[mid] && target >= nums[l]){
                    r = mid - 1;
                }else {
                    l = mid + 1;
                }
            }
        }
        return -1;
    }

    //方法3：通过寻找旋转点来确定在哪一区域做二分法，请参考官方题解

}
```