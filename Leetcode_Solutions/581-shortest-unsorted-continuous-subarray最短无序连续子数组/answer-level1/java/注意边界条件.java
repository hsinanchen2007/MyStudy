### 解题思路
其实就是和排序后的作比较，注意边界条件，全部排列好的情况。

### 代码

```java
class Solution {
    public int findUnsortedSubarray(int[] nums) {
        int[] tmp = Arrays.copyOf(nums, nums.length);
        Arrays.sort(tmp);
        System.out.println(Arrays.toString(tmp));
        System.out.println(Arrays.toString(nums));
        int begin = 0;
        int end = 0;
        for (int i = 0; i < nums.length; i++) {
            if (tmp[i] != nums[i]) {
                begin = i;
                break;
            }
        }
        for (int i = nums.length - 1; i >= 0; i--) {
            if (tmp[i] != nums[i]) {
                end = i;
                break;
            }
        }
//全排好的情况
        if (end == 0) {
            return 0;
        }
        return end - begin + 1;
    }
}
```