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
     * @return Boolean
     */
    function isBalanced($root) {
        if ($root == null) {
            return true;
        }

        return abs($this->isBalancedHelper($root->left) - $this->isBalancedHelper($root->right)) < 2 &&
            $this->isBalanced($root->left) && $this->isBalanced($root->right);
    }

    /**
     *
     * @param mixed $root
     * @return int
     */
    private function isBalancedHelper( $root): int
    {
        if ($root == null) {
            return -1;
        }
        return 1 + max($this->isBalancedHelper($root->left), $this->isBalancedHelper($root->right));
    }
}
```