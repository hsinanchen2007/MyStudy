```
class Solution {

    /**
     * @param TreeNode $root
     * @return Integer
     */
    function rob($root) {
        return max($this->helper($root));
    }
    
    function helper($root){
        $ans = [0,0];
        if($root == null) return $ans;
        $left = $this->helper($root->left);
        $right = $this->helper($root->right);
        $ans[0] = max($left) + max($right); //不抢劫当前节点
        $ans[1] = $root->val + $left[0] + $right[0]; //抢劫当前节点
        return $ans;
    }
}
```
