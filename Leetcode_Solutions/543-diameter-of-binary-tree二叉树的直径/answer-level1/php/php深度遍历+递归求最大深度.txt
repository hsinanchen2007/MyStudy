思路：基本思路就是看了官方的思路，对所有节点进行一次遍历，对每个节点，求经过该节点的最长路径值，全部放入一个数组，最后数组中的最大值就是所求的答案。
- 第一版
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
    private $arr=[];

    function diameterOfBinaryTree($root) {
        $this->preOrder($root);
        return empty($this->arr)?0:max($this->arr); //对空的二叉树进行特殊判断
    }

    //对root为根的二叉树，进行前序遍历
    function preOrder($root){
        if($root==null){
            return;
        }

        //前序操作，求经过该个节点的最长路径值
        $ld=$this->depth($root->left,0);
        $rd=$this->depth($root->right,0);
        $this->arr[]=$ld+$rd;        

        $this->preOrder($root->left);
        $this->preOrder($root->right);
    }

    //求以root为根的二叉树的最大深度
    function depth($root,$depth){
        if($root==null){
            return $depth;
        }

        $lmax=$this->depth($root->left,$depth+1);
        $rmax=$this->depth($root->right,$depth+1);

        return $lmax>$rmax?$lmax:$rmax;
    }
}
```
- 第二版，参照其他网友的方法改进，速度更快
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
    private $max=0;

    function diameterOfBinaryTree($root) {
        $this->depth($root);
        return $this->max;
    }

    function depth($root){
        if($root==null){
            return 0;
        }

        $lmax=$this->depth($root->left);
        $rmax=$this->depth($root->right);

        if(($lmax+$rmax)>$this->max){
            $this->max=$lmax+$rmax;
        }

        return ($lmax>$rmax?$lmax:$rmax)+1;
    }
}
```
