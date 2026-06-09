### 解题思路
暴力检索，两层嵌套循环。

### 代码

```java
class Solution {
    public int[] twoSum(int[] nums, int target) {
        for (int i = 0; i < nums.length; i++) {//nums.length可获得数组长度。
            for (int j = i + 1; j < nums.length; j++) {//两个因子的下标要注意。
                if (nums[j] == target - nums[i]) {//target == nums[j] + nums[i]也是可以的（应该没有差别）。
                    return new int[] { i, j };
                }
            }
        }
        throw new IllegalArgumentException("No two sum solution");//if缺少else语句可能跳出Missing return statement异常。
    }
}


```