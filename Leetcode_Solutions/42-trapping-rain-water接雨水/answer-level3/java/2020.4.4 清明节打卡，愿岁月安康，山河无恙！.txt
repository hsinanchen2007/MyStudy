```
class Solution {
    public int trap(int[] height) {
        int len = height.length;
        if (len == 0)
            return 0;
        int left = 0, right = len - 1;
        int lmax = height[0], rmax = height[len - 1];
        int ans = 0;
        while (left <= right) {
            lmax = Math.max(lmax, height[left]);
            rmax = Math.max(rmax, height[right]);
            if (lmax < rmax)
                ans += lmax - height[left++];
            else
                ans += rmax - height[right--];
        }
        return ans;
    }
}
```
