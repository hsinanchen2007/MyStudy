#### 方法一：递归

本方法非常简单。创建方法 `construct(nums, l, r)`，用于找出在数组 $nums$ 中从 $l$ 到 $r$ 索引（不包含第 $r$ 个位置）中最大二叉树的根节点。

算法步骤如下：

1. 首先调用 `construct(nums, 0, n)`，其中 $n$ 是数组 $nums$ 的长度。

2. 在索引范围 $(l:r-1)$ 内找到最大值的索引，将 $nums[max\_i]$ 作为根节点。

3. 调用 `construct(nums, l, max_i)` 创建根节点的左孩子。递归执行此操作，创建根节点的整个左子树。

4. 类似的，调用 `construct(nums, max_i + 1, r)` 创建根节点的右子树。

5. 方法 `construct(nums, 0, n)` 返回最大二叉树的根节点。

```java [solution1-Java]
public class Solution {
    public TreeNode constructMaximumBinaryTree(int[] nums) {
        return construct(nums, 0, nums.length);
    }
    public TreeNode construct(int[] nums, int l, int r) {
        if (l == r)
            return null;
        int max_i = max(nums, l, r);
        TreeNode root = new TreeNode(nums[max_i]);
        root.left = construct(nums, l, max_i);
        root.right = construct(nums, max_i + 1, r);
        return root;
    }
    public int max(int[] nums, int l, int r) {
        int max_i = l;
        for (int i = l; i < r; i++) {
            if (nums[max_i] < nums[i])
                max_i = i;
        }
        return max_i;
    }
}
```

**复杂度分析**

* 时间复杂度：$O(n^2)$。方法 `construct` 一共被调用 $n$ 次。每次递归寻找根节点时，需要遍历当前索引范围内所有元素找出最大值。一般情况下，每次遍历的复杂度为 $O(\log n)$，总复杂度为 $O\big(n\log n\big)$。最坏的情况下，数组 $nums$ 有序，总的复杂度为 $O(n^2)$。

* 空间复杂度：$O(n)$。递归调用深度为 $n$。平均情况下，长度为 $n$ 的数组递归调用深度为 $O(\log n)$。