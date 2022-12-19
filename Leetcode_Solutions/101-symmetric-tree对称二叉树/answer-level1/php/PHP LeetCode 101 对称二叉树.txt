### 解题思路
递归算法：拆分开就是判断左子树和右子树是否对称

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
        if($root == null){
            return true;
        }
        return $this->isSym($root->left, $root->right);
    }

    function isSym($l,$r){
        if ($l == null && $r == null) return true;
        if ($l == null || $r == null) return false;
        return ($l->val == $r->val) && ($this->isSym($l->left,$r->right)) &&
        ($this->isSym($l->right, $r->left));
    }
}
```

### 解题思路2
迭代算法：利用array模拟队列  先进先出；
同时left和right出队列做对比

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
        $arr = [];
        $bool = true;
        if($root ==null){
            return $bool;
        }
        array_push($arr,$root->left,$root->right);
        while($count = count($arr)){
            $left = array_shift($arr);//
            $right = array_shift($arr);//
            if($left == null && $right == null){
                continue;
            }
            if ($left == null || $right == null){
                $bool = false;break;
            }
            if($left->val != $right->val){
                $bool = false;break;
            }
            array_push($arr,$left->left, $right->right, $left->right, $right->left);
        }
        return $bool;
    }
}
```