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
    function isSymmetric($root) {
        if($root ==null) return true;
        return $this->isSam($root->left,$root->right);
    }

    function isSam($left,$right){
        //如果左节点和右节点都未为null
        if($left ==null && $right == null) return true;
        if($left == null || $right ==null) return false;
        //左节点和右节点的值要相同
        //左子树的左节点要和右子树的右节点相同
        //右子树的左节点要和左节点的右节点相同
        return ($left->val == $right->val) && ($this->isSam($left->left,$right->right)) && ($this->isSam($right->left,$left->right));
    }
}
```