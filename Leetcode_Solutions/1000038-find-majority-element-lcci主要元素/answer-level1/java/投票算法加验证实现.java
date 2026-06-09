仔细看题, 这题和多数元素那题不一样.
类似[2,7,3,5,5]这种, 直接按照投票算法, 结果是5, 但其实结果应该是并不存在.

Tips: 可以考虑评论区的大佬的方法, 最后加一个结果遍历验证就可以，本菜鸡还要继续加油(ง •_•)ง, 附以下题解(加验证的投票算法):
```java
class Solution {
    public int majorityElement(int[] nums) {
        // 投票算法
        int temp = nums[0];
        int count = 1;
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] == temp) {
                count++;
            } else {
                count--;
            }
            if (count == 0) {
                temp = nums[i];
                count = 1;
            }
        }

        // 验证是否满足要求
        int t = nums.length / 2 + 1;
        count = 0;
        for (int num : nums) {
            if (num == temp) count++;
            if (count == t) return temp;
        }
        return -1;
    }
}
```
#### 复杂度分析
- 时间复杂度O(n)
- 空间复杂度O(1)
