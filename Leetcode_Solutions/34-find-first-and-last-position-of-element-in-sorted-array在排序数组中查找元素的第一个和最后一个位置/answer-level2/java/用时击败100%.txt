```
class Solution {
    public int[] searchRange(int[] nums, int target) {
        int[] indexs = {-1,-1};
        if(nums.length<=0){
            return indexs;
        }
        int left = findLeftIndex(nums,target);
        indexs[0] = left;
        int right = findRightIndex(nums,target);
        indexs[1] = right;
        return indexs;
    }

    public int findLeftIndex(int[] nums,int target){
        int start = 0;
        int end = nums.length-1;

        while(start<end){
            int mid = start+(end-start)/2;
            if(nums[mid]==target){
                end = mid;
            }else if(nums[mid]<target){
                start = ++mid;
            }else if(nums[mid]>target){
                end = --mid;
            }

        }
        if(nums[start]==target){
            return start;
        }
        return -1;
    }

    public int findRightIndex(int[] nums,int target){
        int start = 0;
        int end = nums.length-1;

        while(start<end){
            int mid = start+(end-start)/2;
            if(nums[mid]==target){
                start = ++mid;
            }else if(nums[mid]<target){
                start = ++mid;
            }else if(nums[mid]>target){
                end = --mid;
            }
        }
        if(end>=0&&nums[end]==target){
            return end;
        }else if(end>0 && nums[end-1]==target){
            return end-1;
        }
        return -1;
    }
    
}
```

