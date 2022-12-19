### 解题思路
使用递归交换左右子树，完成二叉树反转

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
     * @return TreeNode
     */
    function invertTree($root) {
        return $this->reverseTree($root);
    }

    function reverseTree($tree) {
        if($tree->left == null && $tree->right == null) {
            return $tree;
        }
        //交换左右子树
        $temp = $tree->left;
        $tree->left = $tree->right;
        $tree->right = $temp;

        $this->reverseTree($tree->left);
        $this->reverseTree($tree->right);

        return $tree;
    }
}
```