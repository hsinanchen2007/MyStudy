### 解题思路

检查三种情况：
两树相等是子树
左树是子树
右树是子树

### 性能
执行用时 :88 ms, 在所有 PHP 提交中击败了37.50%的用户
内存消耗 :15.7 MB, 在所有 PHP 提交中击败了50.00%的用户

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
     * @param TreeNode $s
     * @param TreeNode $t
     * @return Boolean
     */
    function isSubtree($s, $t) {
        if ($s == null && $t == null) return true;
        if ($s == null && $t != null) return false;

        return $this->isSametree($s, $t) || $this->isSubtree($s->left, $t) || $this->isSubtree($s->right, $t);
    }

    public function isSametree($s, $t) {
        if ($s == null && $t == null) return true;

        return $s && $t && ($s->val == $t->val) && $this->isSametree($s->left, $t->left) && $this->isSametree($s->right, $t->right);
    }
}
```

### 参考
[LiuQiang评论区](https://leetcode-cn.com/problems/subtree-of-another-tree/comments/49097)