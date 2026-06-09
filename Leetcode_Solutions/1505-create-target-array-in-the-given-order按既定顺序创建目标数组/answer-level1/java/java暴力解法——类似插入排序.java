类似于插入排序中的插入操作，要插入的位置有元素，则将该元素以及其后的元素后移一位。

```
class Solution {
    public int[] createTargetArray(int[] nums, int[] index) {
        int[] ans = new int[nums.length];
        Arrays.fill(ans, -1);
        for (int i = 0; i < nums.length; i++) {
            if (ans[index[i]] != -1 && ans.length - 1 - index[i] >= 0) {
                System.arraycopy(ans, index[i], ans, index[i] + 1, ans.length - 1 - index[i]);
            }
            ans[index[i]] = nums[i];
        }
        return ans;
    }
}
```
