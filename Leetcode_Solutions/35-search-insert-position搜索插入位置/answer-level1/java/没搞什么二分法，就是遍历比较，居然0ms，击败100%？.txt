
依次扫描数组，小于目标值就继续，等于大于目标值就返回当前索引值。
就这么一个朴素算法，居然击败100%。。。。。。

```
class Solution {
    public int searchInsert(int[] nums, int target) {
        int ans = 0;
        for(int i = 0; i < nums.length; i++) {
            if (nums[i] < target) ans = i+1;
            if (nums[i] >= target) return i;
        };
        return ans;
    }
}
```
