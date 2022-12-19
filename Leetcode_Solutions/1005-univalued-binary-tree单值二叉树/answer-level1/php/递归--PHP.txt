### 解题思路
递归，很多时候会单独写一个方法，看起来有点绕。

### 性能
执行用时 :8 ms, 在所有 PHP 提交中击败了66.67%的用户
内存消耗 :15 MB, 在所有 PHP 提交中击败了42.86%的用户

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
    function isUnivalTree($root) {
        if ($root == null) return true;

        if ($root->left != null && $root->left->val != $root->val) return false;

        if ($root->right != null && $root->right->val != $root->val) return false;

        return $this->isUnivalTree($root->left) && $this->isUnivalTree($root->right);
    }
}
```

### 算法复杂度
- 时间复杂度
- 空间复杂度

### 参考
[https://leetcode-cn.com/problems/univalued-binary-tree/solution/php-by-bian-luo-huan/](https://leetcode-cn.com/problems/univalued-binary-tree/solution/php-by-bian-luo-huan/)