### 解题思路
对于mid和target,有三种情况：
1.nums[mid] < target,找右边；
2.nums[mid] > target,找左边；
3.nums[mid] = target,定义双指针左右搜索。
返回值为计数。
### 代码

```java
class Solution {
    public int search(int[] nums, int target) {
        if(nums == null || nums.length == 0) return 0;
        int lo = 0 , hi = nums.length-1;
        return binarySearch(nums,lo,hi,target);
    }
    private int binarySearch(int[] nums,int lo,int hi,int target){
        int count = 0;
        if(lo == hi) return nums[lo] == target ? ++count : 0;
        int mid = (lo + hi)/2;
        if(lo < mid && nums[mid] > target){
            count += binarySearch(nums,lo,mid-1,target);
        }else if(mid < hi && nums[mid] < target){
            count += binarySearch(nums,mid+1,hi,target);
        }else{
            int i = mid , j = mid-1;
            while(i < nums.length && nums[i++] == target) count++;
            while(j >= 0 && nums[j--] == target) count++;
        }
        return count;
    }
}
```