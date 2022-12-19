先遍历一次求出总和，作为rightsum（leftsum初始为0）。
然后再遍历一次数组，每次rightsum减当前元素，此时如果rightsum和leftsum相等，就找到了中心索引，中断遍历。
如果不等，则leftsum加上当前元素后，继续遍历。

```
class Solution {
    public int pivotIndex(int[] nums) {
        int ans = -1;
        int leftsum = 0;
        int rightsum = 0;
        for (int i = 0; i < nums.length; i++) rightsum += nums[i];
        for (int i = 0; i < nums.length; i++) {
            rightsum -= nums[i];
            if (leftsum == rightsum) {
                ans = i;
                break;
            } else {
                leftsum += nums[i];
            };
        };
        return ans;
    }
}
```
