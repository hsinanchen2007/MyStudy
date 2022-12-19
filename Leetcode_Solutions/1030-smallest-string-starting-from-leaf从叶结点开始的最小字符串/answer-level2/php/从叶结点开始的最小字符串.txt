```
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
     * @return String
     */
   public $res = 'zzzzzzzzzzzzzzzzzzzzz';
    function smallestFromLeaf($root) {
        $this->helper($root,chr(97 + $root->val));
        return $this->res;
    }

    function helper($root,$str=''){
        if($root->left === NULL && $root->right === NULL){
            if($this->res > $str){
                $this->res = $str;
            }
            return;
        }

        if($root->left !== NULL){
            $this->helper($root->left,chr(97 + $root->left->val).$str);
        }

        if($root->right !== NULL){
            $this->helper($root->right,chr(97 + $root->right->val).$str);
        }
    }
}
```
