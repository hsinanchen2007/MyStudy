```
class Solution {

    /**
     * @param TreeNode $root
     * @return Integer
     */
    function sumNumbers($root) {
        $this->dfs($root,$root->val);
        return $this->sum;
    }
    
    private $sum = 0;
    
    function dfs($root,$cursum){
        if($root->left == null && $root->right == null){
            $this->sum += $cursum;
            return;
        }
        if($root->left != null) $this->dfs($root->left,$cursum*10+$root->left->val);
        if($root->right != null) $this->dfs($root->right,$cursum*10+$root->right->val);
    }
}
```
