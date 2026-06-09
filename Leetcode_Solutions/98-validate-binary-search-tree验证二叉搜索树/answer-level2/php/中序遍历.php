```
class Solution {

    /**
     * @param TreeNode $root
     * @return Integer[][]
     */
    function isValidBST($root) {
        $a = PHP_INT_MIN;
        return $this->inOrder($root, $a);
    }
    function inOrder($root, &$a){
        if($root != null){
            if(!$this->inOrder($root->left, $a)) return false;         
            if($a < $root->val){
                $a = $root->val;
            }else{
                return false;
            }
            if(!$this->inOrder($root->right, $a)) return false;
        }
        return true;
    }
}
```
