> 翻译自英文站 [remove-duplicates-from-sorted-array-ii](https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/discuss/27976/3-6-easy-lines-C%2B%2B-Java-Python-Ruby)

#### 方法 1: 递归

**思路**

最简单的策略是使用递归。

**代码**

```java
public int removeDuplicates(int[] nums) {
    int i = 0;
    for (int n : nums)
        if (i < 2 || n > nums[i-2])
            nums[i++] = n;
    return i;
}
```

**复杂度分析**

- 时间复杂度：O(N)，其中N是数组数。
- 空间复杂度：O(1)。


Analysis written by @[StefanPochmann](https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/discuss/27976/3-6-easy-lines-C%2B%2B-Java-Python-Ruby)