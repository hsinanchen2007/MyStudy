### 解题思路
核心思想是二分法！！！
为了通过检测奇怪的用例，增加了find标志！！！
例如：[0,1]本身就不缺数据，预期返回2！！！

### 代码

```java
class Solution {
    int index = 0;
    boolean find = false;
    public int missingNumber(int[] nums) {
        // 二分法？？？
        if (nums == null || nums.length == 0) {
            return -1;
        }

        func(nums, 0, nums.length - 1);
        if (!find) {
            return nums[nums.length - 1] + 1;
        }
        return index;
    }

    private void func(int[] nums, int left, int right) {
        if (left == right)  {
            if (left < nums[left]) {
                index = left;
                find = true;
            }
            return;
        }
        int mid = (left + right) / 2;
        if (mid == nums[mid]) {
            func(nums, mid + 1, right);
        }
        func(nums, left, mid);
    }
}
```