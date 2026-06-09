### 解题思路
深度优先遍历

### 性能
执行用时 :8 ms 在所有 PHP 提交中击败了62.50%的用户
内存消耗 :14.7 MB, 在所有 PHP 提交中击败了100.00%的用户

### 代码

```php
/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     public $val = null;
 *     public $left = null;
 *     public $right = null;
 *     function __construct($value) { $this->val = $value; }
 * }
 */
class Solution {

    /**
     * @param TreeNode $root1
     * @param TreeNode $root2
     * @return Boolean
     */
    function leafSimilar($root1, $root2) {
        $leaves1 = $leaves2 = [];
        $this->dfs($root1, $leaves1);
        $this->dfs($root2, $leaves2);

        return $leaves1 == $leaves2;
    }

    public function dfs($node, &$leaves)
    {
        if ($node == null) return;

        if ($node->left == null && $node->right == null) $leaves[] = $node->val;
        $this->dfs($node->left, $leaves);
        $this->dfs($node->right, $leaves);
    }
}
```

### 算法复杂度
- 时间复杂度：O（N）
- 空间复杂度：O(N)

### 参考
[https://leetcode-cn.com/problems/leaf-similar-trees/solution/xie-zi-xiang-si-de-shu-by-leetcode/
](https://leetcode-cn.com/problems/leaf-similar-trees/solution/xie-zi-xiang-si-de-shu-by-leetcode/)
