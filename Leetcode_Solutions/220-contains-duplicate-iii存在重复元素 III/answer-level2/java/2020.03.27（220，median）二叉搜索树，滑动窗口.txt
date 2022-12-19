### 解题思路
本题测试案例会造成溢出，所以应该用`Long`来**防止溢出**

- 题目要求在区间 [`i`, `i + k`] 是否存在两个数`nums[i]`和`nums[j]`**之差的绝对值**小于等于 t

- 由数学知识可知，$| a - b | <= c$，式子展开有 $b - c <= a <= b + c$

- 去掉`a`这个中间量来讲也就是只要满足**左边的最大值小于等于右边**即可

- 那这里就需要用到`TreeSet`中的`ceiling()`方法（取最大值）来**取得左边的最大值**

- 之后的步骤和上一题`219`是一样的，具体参考代码注释。

### 代码

```java []
class Solution {
    public boolean containsNearbyAlmostDuplicate(int[] nums, int k, int t) {
        int n = nums.length;
        // 定义平衡二叉搜索树来存放元素，这里因为防止溢出用到了 Long
        TreeSet<Long> set = new TreeSet<>();
        for (int i = 0; i < n; i++) {
            // 查找表中应该满足大于等于 nums[i] - t 且小于等于 nums[i] + t 的值
            Long ceil = set.ceiling((long)nums[i] - t);
            if (ceil != null && ceil <= (long)nums[i] + t) {
                return true;
            }
            set.add((long)nums[i]);
            // 如果放入当前遍历到的元素后会超过 k 则删除 k 区间的第一个元素
            if (set.size() > k) {
                set.remove((long)nums[i - k]);
            }
        }
        return false;
    }
}
```