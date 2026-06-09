### 解题思路
先序遍历
中序
后序
都可以
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
     * @param TreeNode $t1
     * @param TreeNode $t2
     * @return TreeNode
     */
    function mergeTrees($t1, $t2) {
        //临界条件
        if($t1 == null) return $t2;
        if($t2 == null) return $t1;
        //新的值等于 t1.val+t2.val;
        $t1->val += $t2->val; 
        //新的左子树 = t1.left + t2.left;
        $t1->left = $this->mergeTrees($t1->left,$t2->left);
        $t1->right = $this->mergeTrees($t1->right,$t2->right); 

        return $t1;
    }
}
```