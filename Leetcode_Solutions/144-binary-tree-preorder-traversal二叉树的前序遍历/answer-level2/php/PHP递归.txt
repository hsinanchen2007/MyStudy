# PHP递归
执行用时 :4 ms, 在所有 PHP 提交中击败了91.41%的用户
内存消耗 :15 MB, 在所有 PHP 提交中击败了44.44%的用户






```
class Solution {

    /**
     * @param TreeNode $root
     * @return Integer[]
     */
    public $ans=[];    
    function preorderTraversal($root) {
        if($root!=null)
        {
            array_push($this->ans,$root->val);
            $this->preorderTraversal($root->left);
            $this->preorderTraversal($root->right);
        }
        return $this->ans;
    }
}
```
