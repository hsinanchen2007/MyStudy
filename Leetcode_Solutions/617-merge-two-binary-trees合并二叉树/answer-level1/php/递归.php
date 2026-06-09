### 解题思路
递归代码最简单，但是最不容易理解。
问题的核心是：同时遍历两个二叉树。
每一次递归都要把两个树的结点值相加或者添加新结点。
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
        if($t1==null) return $t2;
        if($t2==null) return $t1;
        $t1->val+=$t2->val;
        $t1->left=$this->mergeTrees($t1->left,$t2->left);
        $t1->right=$this->mergeTrees($t1->right,$t2->right);
        return $t1;
    }
/*
    function traveTree($t){//前序遍历二叉树
        if($t->val==0) return null;
        echo $t->val;
        $this->traveTree($t->left);
        $this->traveTree($t->right);
    } 
*/
}
```