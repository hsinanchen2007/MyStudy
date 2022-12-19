### 解题
二分搜索两次，第一次找到最左边的，第二次找到最右边的

### 代码

```java
class Solution {
    public int[] searchRange(int[] nums, int target) {
        int[] res = {-1,-1};
        if(nums==null||nums.length==0)
            return res;
        
        res[0] = leftest(nums,target);
        res[1] = rightest(nums,target);
        return res;
    }
    public int leftest(int[] nums,int target){
        int left = 0,right = nums.length-1;
        while(left+1<right){
            int mid = left+(right-left)/2;
            if(nums[mid]>=target)
                right = mid;
            else if(nums[mid]<target)
                left = mid;
            // else{
            //     // if(nums[mid]!=nums[mid-1])
            //     //     return mid;
            //     right = mid;
            // }
        }
        if(nums[left]==target) return left;
        if(nums[right]==target) return right;
        return -1;
    }
    public int rightest(int[] nums,int target){
        int left = 0,right = nums.length-1;
        while(left+1<right){
            int mid = left+(right-left)/2;
            if(nums[mid]>target)
                right = mid;
            else if(nums[mid]<=target)
                left = mid;
            // else{
            //     left = mid;
            // }
        }
        if(nums[right]==target) return right;
        if(nums[left]==target) return left;
        
        return -1;
    }
}
```