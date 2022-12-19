### 解题思路
递归呗

### 性能
执行用时 :20 ms, 在所有 PHP 提交中击败了33.33%的用户
内存消耗 :16.7 MB, 在所有 PHP 提交中击败了100.00%的用户

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
    function findTilt($root) {
        if ($root == null) return 0;

        $sum = 0;
        $this->traverse($root, $sum);

        return $sum;
    }

    public function traverse($node, &$sum)
    {
        if ($node == null) return 0;

        $left = $this->traverse($node->left, $sum);
        $right = $this->traverse($node->right, $sum);

        $sum += abs($left - $right);

        return $left + $right + $node->val;
    }
}
```