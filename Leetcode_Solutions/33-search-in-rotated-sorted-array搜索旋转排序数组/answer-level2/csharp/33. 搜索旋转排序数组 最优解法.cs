### 解题思路
利用中点左右的区间始终有一边有序的性质可以晒掉一边，如果目标在有序的一边，那么就是普通的二分。
### 代码

```csharp
public class Solution {
    public int Search(int[] nums, int target) {
       int len = nums.Length;
       int l = 0;
       int r = len - 1;
       while(l <= r) {
           int mid = (l+r)>>1;
           if(nums[mid] == target) return mid; //排除mid位置方便书写
           if(nums[l] <= nums[r]) { //有序
                if(nums[mid] > target) {
                    r  = mid - 1;
                } else {
                    l = mid + 1;
                }
           } else { //无序
               if(nums[l] <= nums[mid] && nums[mid] > nums[r]) { //左边有序
                if(target >= nums[l] && target < nums[mid]) { //在左边
                    r = mid-1;
                } else {
                    l = mid +1;
                }
           } else if(nums[l] >= nums[mid] && nums[mid] < nums[r]) { //右边有序
                if(target > nums[mid] && target <= nums[r]) { //在右边
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
           } 
           }
       }
       return -1;
    }
}
```