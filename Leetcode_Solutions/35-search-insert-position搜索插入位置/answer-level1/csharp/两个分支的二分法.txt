看了很多题解，都是三分支，其实两个分支就够了。。。

```
public class Solution {
    public int SearchInsert(int[] nums, int target) {
        int l = 0;
        int r = nums.Length - 1;
        while (l < r) {
            int m = (l + r) / 2;
            if (target <= nums[m])
                r = m - 1;
            else
                l = m + 1;
        }
        return target <= nums[l] ? l : l + 1;
    }
}
```
