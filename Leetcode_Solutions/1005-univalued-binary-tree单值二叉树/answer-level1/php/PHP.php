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
     * @return Boolean
     */
    function isUnivalTree($root) {
        $val = $root->val;
        return $this->helper($root->left,$val) && $this->helper($root->right,$val);
    }

    public function helper($root,$val){
        if ($root==null){
            return true;
        }
        if ($root->val!=$val){
            return false;
        }
        return $this->helper($root->left,$val) && $this->helper($root->right,$val);
    }
}
```
