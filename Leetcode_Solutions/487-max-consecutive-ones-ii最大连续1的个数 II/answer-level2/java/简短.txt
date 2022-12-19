```
class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int l, r, c = 0;
        for (l = 0, r = 0; r < nums.length; ++r) {
            c += nums[r];
            if (r - l + 1 > c + 1) c -= nums[l++];
        }
        return r - l;
    }
}
```
