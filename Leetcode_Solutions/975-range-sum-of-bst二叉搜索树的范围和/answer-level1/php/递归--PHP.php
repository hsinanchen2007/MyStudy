### 解题思路
注意是二叉搜索树，重点在于理解是介于L和R直接的数，不是树上L结合R节点之间的节点和。

### 性能
执行用时 :96 ms, 在所有 PHP 提交中击败了92.00%的用户
内存消耗 :22.8 MB,在所有 PHP 提交中击败了5.26%的用户

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
     * @param Integer $L
     * @param Integer $R
     * @return Integer
     */
    function rangeSumBST($root, $L, $R) {
        if ($root == null) return 0;

        if ($root->val > $R) {
            return $this->rangeSumBST($root->left, $L, $R);
        } elseif ($root->val < $L) {
            return $this->rangeSumBST($root->right, $L, $R);
        } else {
            return $root->val + $this->rangeSumBST($root->left, $L, $R) + $this->rangeSumBST($root->right, $L, $R);
        }
    }
}
```