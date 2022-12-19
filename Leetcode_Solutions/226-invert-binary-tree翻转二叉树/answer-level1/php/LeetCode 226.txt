### 解题思路
递归算法：核心思想就是左右树对调

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
        //左右数对调

        if($root == null) return null;

        list($root->left,$root->right) = [$this->invertTree($root->right),$this->invertTree($root->left)];

        return $root;
    }
}
```