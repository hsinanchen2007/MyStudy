### 解题思路
分开考虑。。。

### 代码

```java
class Solution {
    public int[] searchRange(int[] nums, int target) {
        int len = nums.length;
        if(len == 0){
            return new int[]{-1,-1};
        }
        int start = findStart(nums,target);
        if(start == -1){
            return new int[]{-1,-1};
        }
        int end = findEnd(nums, target);
        return new int[]{start, end};
    }
    
    private int findStart(int[] nums, int target){
        int left = 0;
        int right = nums.length-1;
        while(left<right){
            int mid = left + (right-left)/2;
            if(nums[mid]<target){
                //小于target一定不是第一个位置
                //下一轮搜索区间为[mid+1,right]
                left = mid+1;
            }
            else{
                right = mid;
            }
        }  
        if(nums[left] == target){
            return left;
        }
        else{
            return -1;
        }
    }
    
    private int findEnd(int[] nums, int target){
        int left = 0;
        int right = nums.length-1;
        while(left<right){
            int mid = left + (right-left+1)/2;
            if(nums[mid] > target){
                //大于target一定不是最后一个位置
                //下一轮搜索区间为[left, mid-1]
                right = mid-1;
            }
            else{
                left = mid;
            }
        }
        return left;
    }
}
```