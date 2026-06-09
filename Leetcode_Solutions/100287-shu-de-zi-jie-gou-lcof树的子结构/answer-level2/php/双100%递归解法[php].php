### 解题思路
具体解法见代码

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
     * @param TreeNode $A
     * @param TreeNode $B
     * @return Boolean
     */
    function isSubStructure($A, $B) {
        if($A == null || $B==null){
            return false;
        }
        //递归比较，只要是子树就行，所以用或的关系
        return $this->helper($A,$B) || $this->isSubStructure($A->left,$B) || $this->isSubStructure($A->right,$B);
    }

    function helper($A,$B){
        //A、B只要有1个空了，如果不是B空，那就返回false
        if($A==null || $B==null){
            return $B==null ? true : false;
        }
        
        //值如果不相等，也返回false
        if($A->val != $B->val){
            return false;
        }
        
        //左子树与左子树、右子树与右子树比较
        return $this->helper($A->left,$B->left) && $this->helper($A->right,$B->right);
    }
}


```