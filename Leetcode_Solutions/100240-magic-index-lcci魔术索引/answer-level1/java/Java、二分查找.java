本来想用暴力法过，但是想来想去觉得有点可惜，所以还是用二分查找来解决吧

```
class Solution {
    public int findMagicIndex(int[] nums) {
        int left = 0, right = nums.length;

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] != mid) {
                if (nums[mid] >= 0) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            } else {
                left = mid + 1;
            }
        }
        return left - 1;
    }
}
```

但是在我通过以后再来理解我的代码还有点想不通，这可能就是二分查找的魔力吧，希望有看懂我代码的大佬给我讲讲怎么来的哈哈哈
