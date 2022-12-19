
```java
class Solution {
    public int search(int[] nums, int target) {
        if(nums == null || nums.length < 1) return 0;
        //查找target的最小index
        int i1 = findNum(nums,target);
        //查找target+1的最小index(如果不存在target+1的话index=target的最大坐标+1)
        int i2 = findNum(nums,target + 1);
        // target大于数组里的最大数
        if(i1 >= nums.length) return 0; 
        //target存在且只有一个,或者target小于数组的最小值    
        if(i1 == i2 && nums[i1] == target) return 1; 
        // target不止一个
        return i2-i1;
    }
    //二分 查找某个数返回下标
    //若该数有重复值返回其最小下标
    //该数<数组最小值，返回下标0
    //该数>数组最大值，返回下标nums.length
    //若 nums[i] <target <nums[i+1]  则返回i+1      例如：[0,1,3] target = 2  返回的i=2 
    private int findNum(int[] nums,int target){
        int i = 0,j = nums.length;
        while(i < j ){
            int mid = i + (j - i)/2;
            if( target <= nums[mid]){
                j = mid;
            }else if(nums[mid] < target){
                i = mid + 1;
            }else{
                j = mid;
            }
        }
        return i;
    }
}
```