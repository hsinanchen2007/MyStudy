### 解题思路
此处撰写解题思路

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
     * @return Integer
     */
    function minDepth($root) {
        if ($root == null) {
            return 0;
        }

        if ($root->left == null && $root->right == null) {
            return 1;
        }
        $mini_depth = PHP_INT_MAX;
        if ($root->left != null) {
            $mini_depth = min($this->minDepth($root->left), $mini_depth);
        }

        if ($root->right != null) {
            $mini_depth = min($this->minDepth($root->right), $mini_depth);
        }

        return $mini_depth + 1;
    }
}
```