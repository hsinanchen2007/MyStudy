### 解题思路
递归实现。

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
    function preorderTraversal($root) {
        $res = [];
        if ($root == null) return $res;

        $this->task($root, $res);

        return $res;
    }

    public function task($node, &$res)
    {
        if ($node == null) return $res;

        $res[] = $node->val;
        $this->task($node->left, $res);
        $this->task($node->right, $res);
    }
}
```

### 性能
执行用时 :8 ms, 在所有 PHP 提交中击败了54.92%的用户
内存消耗 :15 MB, 在所有 PHP 提交中击败了63.64%的用户

### 算法复杂度
-- 时间复杂度 O(N)
-- 空间复杂度 O(N)

### 参考