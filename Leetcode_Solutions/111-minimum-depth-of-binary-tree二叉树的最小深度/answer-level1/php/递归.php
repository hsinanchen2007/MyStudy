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

        $deep = PHP_INT_MAX;
        if ($root->left != null) {
            $deep = min($this->minDepth($root->left), $deep);
        }
        if ($root->right != null) {
            $deep = min($this->minDepth($root->right), $deep);
        }

        return $deep + 1;
    }
}
```