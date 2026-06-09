### 解题思路
一个树是另一个树的子树的三种情况

要么这两个树相等
要么这个树是左树的子树
要么这个树是右树的子树

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
    function isSubtree($s, $t)
    {
        if ($s == null && $t == null) {
            return true;
        }
        if ($s == null && $t != null) {
            return false;
        }

        return $this->isSameTree($s, $t)//判断2个树是否相等
            || $this->isSubtree($s->left, $t)//左子树和比较树是否相等
            || $this->isSubtree($s->right, $t);//右子树和比较树是否相等
    }

    /**
     * 比较2个树是否相等
     * @param TreeNode $s
     * @param TreeNode $t
     * @return bool
     */
    function isSameTree($s, $t)
    {
        if ($s == null && $t == null) {
            return true;
        }

        return $s && $t//都不为空
            && $s->val == $t->val//当前节点值相等
            && $this->isSameTree($s->left, $t->left)//左节点比较
            && $this->isSameTree($s->right, $t->right);//右节点比较
    }
}
```
## 参考
[评论区](https://leetcode-cn.com/problems/subtree-of-another-tree/comments/)
[572. 另一个树的子树](https://leetcode-cn.com/problems/subtree-of-another-tree/solution/di-gui-php-by-salmonl-5/)