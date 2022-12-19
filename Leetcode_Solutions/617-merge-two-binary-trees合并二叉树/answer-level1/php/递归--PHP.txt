### 解题思路
递归

### 性能
执行用时 :24 ms, 在所有 PHP 提交中击败了76.00%的用户
内存消耗 :15.6 MB, 在所有 PHP 提交中击败了20.00%的用户

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
     * @param TreeNode $t1
     * @param TreeNode $t2
     * @return TreeNode
     */
    function mergeTrees($t1, $t2) {
        if ($t1 == null) return $t2;
        if ($t2 == null) return $t1;

        $t1->val += $t2->val;
        $t1->left = $this->mergeTrees($t1->left, $t2->left);
        $t1->right = $this->mergeTrees($t1->right, $t2->right);

        return $t1;
    }
}
```