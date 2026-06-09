暴力解法：
```
function countNodes($root) {
    return $root==null ? 0 : $this->countNodes($root->left) + $this->countNodes($root->right) + 1;
}
```
利用完全二叉树特性：
```
class Solution {

    /**
     * @param TreeNode $root
     * @return Integer
     */
    function countNodes($root) {
        if($root == null) return 0;
        $ld = $this->getDepth($root->left);
        $rd = $this->getDepth($root->right);
        if($ld == $rd){
            return $this->countNodes($root->right) + pow(2,$ld);
        }else{
            return $this->countNodes($root->left) + pow(2,$rd);
        }
    }
    
    function getDepth($root){
        $depth = 0;
        while($root != null){
            $depth ++;
            $root = $root->left;
        }
        return $depth;
    }
}
```
