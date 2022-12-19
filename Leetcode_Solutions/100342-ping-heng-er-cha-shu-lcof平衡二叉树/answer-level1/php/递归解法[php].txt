### 解题思路
见代码，比较好理解

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
    function isBalanced($root) {
        if($root == null) return true;
        if(abs($this->getDepth($root->left) - $this->getDepth($root->right))>1){
            return false;
        }
        return $this->isBalanced($root->left) && $this->isBalanced($root->right);
    }

    //获取树的深度
    function getDepth($root){
        if($root == null) return 0;
        return max($this->getDepth($root->left),$this->getDepth($root->right))+1;
    }
}
```