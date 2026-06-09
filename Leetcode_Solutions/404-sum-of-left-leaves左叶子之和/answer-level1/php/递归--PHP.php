### 解题思路
递归

### 性能
执行用时 :4 ms, 在所有 PHP 提交中击败了100.00%的用户
内存消耗 :15.5 MB, 在所有 PHP 提交中击败了50.00%的用户

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
    function sumOfLeftLeaves($root) {
        if ($root == null) {
            return 0;
        }

        $sum = 0;
        if ($root->left != null && $root->left->left == null && $root->left->right == null) {
            $sum += $root->left->val;
        }

        return $this->sumOfLeftLeaves($root->left) + $this->sumOfLeftLeaves($root->right) + $sum;
    }
}
```