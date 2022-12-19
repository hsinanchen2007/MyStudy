### 解题思路
[26. 删除排序数组中的重复项](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/solution/javashuang-zhi-zhen-by-reversal/)

原理与26题一样，增加了使用count来实现每个元素最多出现两次的逻辑。

### 代码

```java
class Solution {
    public int removeDuplicates(int[] nums) {
        if (nums == null || nums.length == 0)
            return 0;
        int k = 0;
        int flag = nums[0] - 1;
        int len = nums.length;
        int count = 0;
        for (int i = 1; i < len; i++) {
            if (nums[i] == nums[k]) {
                if (count > 0) {
                    nums[i] = flag;
                } else {
                    count++;
                }
            } else {
                k = i;
                count = 0;
            }
        }

        int result = 0;
        for (int i = 0; i < len; i++) {
            if (nums[i] != flag) {
                if (i != result) {
                    int temp = nums[i];
                    nums[i] = nums[result];
                    nums[result] = temp;
                }
                result++;
            }
        }
        return result;
    }
}

```