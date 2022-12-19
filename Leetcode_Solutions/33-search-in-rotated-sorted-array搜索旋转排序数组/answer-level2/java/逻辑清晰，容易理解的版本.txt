1. 普通的有序数组的二分查找
```Java
class Solution{
    public int search(int[] nums,int target){
        int left = 0;
        int right = nums.length-1;
        while(left<=right){
            int middle = left+(right-left)/2;
            if(nums[middle]>target) 
                right = middle-1;
            else if(nums[middle]<target) 
                left = middle+1;
            else 
                return middle;
        }
        return -1;
    }
}
```


2. 旋转有序数组的二分查找
```Java
class Solution {
    public int search(int[] nums,int target){
        int left = 0;
        int right = nums.length-1;
        while(left<=right){
            int mid = left+(right-left)/2;
            if(nums[mid] == target)return mid;

            if(nums[left]<=nums[mid]) { //left～mid这一段是升序
                if(nums[left] <=target && target < nums[mid]){
                    //如果target在left-mid这一段中，那么下次就在left ～ mid-1这一段中寻找
                    right = mid-1;
                }else{
                    // 否则需要在另外半边中寻找
                    left = mid+1;
                }
            }else{ //否则mid～right这一段一定是升序
                if(nums[mid] <target && target<=nums[right]){
                    //如果target在mid-right这一段中，那么下次就在mid+1 ～ right这一段中寻找
                    left = mid+1;
                }else{
                    // 否则需要在另外半边中寻找
                    right = mid-1;
                }
            }
        }
        return -1;
    }
}
```
主要的思想是，每次取得mid，那么两部分一定有一个是严格有序的。
如果在严格有序的部分中不存在，那么就去另外一部分中去寻找
