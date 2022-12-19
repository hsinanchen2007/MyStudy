### 解题思路
层次遍历，使用map存储没层最大值。

### 性能
执行用时 :12 ms, 在所有 PHP 提交中击败了92.86%的用户
内存消耗 :17.7 MB, 在所有 PHP 提交中击败了11.11%的用户

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
     * @param TreeNode $root
     * @return Integer[]
     */
    function largestValues($root) {
        $res = [];
        $this->levelOrder($root, 0, $res);

        return $res;
    }

    // 层次遍历
    public function levelOrder($node, $level, &$map)
    {
        if ($node == null) return;
        if ($level >= count($map)) {
            $map[$level] = $node->val;
        } else {
            if ($node->val > $map[$level]) $map[$level] = $node->val;
        }

        $this->levelOrder($node->left, $level + 1, $map);
        $this->levelOrder($node->right, $level + 1, $map);
    }
}
```

### 算法复杂度
- 时间复杂度 O(N)
- 空间复杂度 O(1)

### 参考
[https://leetcode-cn.com/problems/find-largest-value-in-each-tree-row/comments/169649](https://leetcode-cn.com/problems/find-largest-value-in-each-tree-row/comments/169649)