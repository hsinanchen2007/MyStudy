### 解题思路

先对目标数组进行排序，排序后后面的数字必定大于等于前面的，只需要向后查找即不会出现重复并可快速判断：

1. 如果数字已经出现过，则跳过
2. 如果两种的差已经超过k，即可跳过（越往后差只会增大）
3. 如果满足条件，计数器加一，跳出循环继续下一轮判断

![image.png](https://pic.leetcode-cn.com/22b7ef4710b4e0b2977b0fce3ab44bb98eef30d86287a5bbcd8ab20078b219ad-image.png)

### 代码

```java
class Solution {
    public int findPairs(int[] nums, int k) {
        if(nums.length < 2) {
            return 0;
        }
        Arrays.sort(nums);
        int ret = 0;
        int tmp = nums[0] - 1;
        for (int i = 0; i < nums.length - 1; i++) {
            if (nums[i] == tmp) {
                continue;
            }
            for (int j = i + 1; j < nums.length; j++) {
                if (nums[j] - nums[i] > k) {
                    break;
                }
                if (nums[i] + k == nums[j]) {
                    ret += 1;
                    break;
                }
            }
            tmp = nums[i];
        }
        return ret;
    }
}
```