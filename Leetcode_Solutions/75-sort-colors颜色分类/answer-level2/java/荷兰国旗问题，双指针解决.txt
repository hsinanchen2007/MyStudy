### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public void sortColors(int[] nums) {
        int n = nums.length;
        int p0 = 0;
        int p2 = n - 1;
        int i = 0;
        // 应该取等于
        while (i <= p2) {
            if (nums[i] == 0) {
                swap(nums, p0, i);
                p0++;
                // 因为从前面换回来的必定是 1，注意i++
                i++;
            } else if (nums[i] == 2) {
                swap(nums, p2, i);
                p2--;
            } else {
                i++;
            }
        }
    }
    public void swap(int[] nums, int x, int y) {
        int temp = nums[x];
        nums[x] = nums[y];
        nums[y] = temp;
    }
}
```