### 解题思路
二分查找大第一个大于target的位置，然后线性查找最后一个的位置
### 代码

```csharp
public class Solution {
    public int[] SearchRange(int[] nums, int target) {
        int len = nums.Length;
        int[] ans = new int[]{-1,-1};
        if(len == 0) return ans;
        int l = 0;
        int r = len;
        while(l < r) {
            int mid = (l+r) >> 1;
            if(nums[mid] >= target) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        if(r < len &&nums[r] == target) {
            ans[0] = r;
            for(; r < len; r ++) {
                if(nums[r] != target) break;
            }
            ans[1] = r-1;
            return ans; 
        } else {
            return ans;
        }
    }
}
```