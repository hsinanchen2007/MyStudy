方法一：直接遍历，最小值在开头或结尾，或者中间。
```java
class Solution {
    public int findMin(int[] nums){
        for(int i = 1; i< nums.length; i++){
            if(nums[i] < nums[0] && nums[i] <= nums[nums.length-1]){
                return nums[i];
            }
        }
        return nums[0];
    }
}
```

方法二：二分查找的方法
```java
class Solution {
    public int findMin(int[] nums) {
        int left = 0;
        int right = nums.length - 1;
        while(left < right){
            int mid = left + (right-left) / 2;
            if(nums[left] < nums[right]){
                right = left;
            }else if(nums[left] > nums[right] && nums[right-1] > nums[right]){
                left = right;
            }else{
                if(nums[mid] > nums[left]){
                    left = mid;
                }else{
                    right = mid;
                }
            }
        }
        return nums[left];
    }
}
```