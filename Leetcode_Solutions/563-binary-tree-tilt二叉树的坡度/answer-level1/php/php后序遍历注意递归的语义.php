思路：就是借鉴官方的思路，后序遍历
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
     * @return Integer
     */

    private $res=0;
    
    function findTilt($root) {
        $this->postOrder($root);
        return $this->res;
    }

    //后序遍历，返回以root为根的二叉树的所有节点的和
    function postOrder($root){
        if($root==null){
            return 0;
        }

        $lv=$this->postOrder($root->left);
        $rv=$this->postOrder($root->right);

        $this->res+=abs($lv-$rv);

        return $lv+$rv+$root->val;
    }
}
```
