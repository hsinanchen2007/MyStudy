### 解题思路
1. 首先判断特殊情况，如果数组为空则返回1；
2. 数组中缺失的最小整数只可能是在 1 到 n+1 范围内，n是指数组的大小，因此从1开始遍历n次，如果判断数组内不存在i则可以确定缺失值；如果循环结束，数组存在n，则说明缺失的最小整数是n+1；

### 代码

```java
class Solution {
    public int firstMissingPositive(int[] nums) {
        int len = nums.length;
        if (len == 0) {
            return 1;
        }
        for (int i = 1; i < len + 1; i++) {
            if (!containsKey(nums, i)) {
                return i;
            }
        }
        return len + 1;
    }

    private boolean containsKey(int[] nums, int key) {
        for (int i = 0; i < nums.length; i++) {
            if(nums[i] == key) {
                return true;
            }
        }
        return false;
    }
}
```