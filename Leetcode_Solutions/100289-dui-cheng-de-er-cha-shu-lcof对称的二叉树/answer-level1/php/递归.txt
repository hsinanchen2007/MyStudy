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
        if(empty($root)){
            return true;
        }
        return $this->help($root->left,$root->right);
    }
    function help($left,$right){
        if($left==null && $right==null){
            return true;
        }
        if($left==null || $right==null || $left->val!=$right->val){
            return false;
        }
       return  $this->help($left->left,$right->right) && $this->help($left->right,$right->left);
    }
}
```