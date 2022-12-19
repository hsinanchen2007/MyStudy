二叉树的前序遍历，中序遍历，后序遍历都可以解
```
class Solution {

    /**
     * @param TreeNode $root
     * @param Float $target
     * @return Integer
     */
    function closestValue($root, $target) {
        $min = PHP_INT_MAX;
        $ans = null;
        $this->helper($root,$target,$min,$ans);
        return $ans;
    }

    function helper($node,$target,&$min,&$ans){
        if($node == null) return ;
        if(abs($target - $node->val) < $min){
            $min = abs($target - $node->val);
            $ans = $node->val;
        }
        $this->helper($node->left, $target, $min, $ans);
        $this->helper($node->right, $target, $min, $ans);
    }
}
```
