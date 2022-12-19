中序遍历
```
class Solution {

    /**
     * @param TreeNode $root
     * @param Integer $k
     * @return Integer
     */
    function kthSmallest($root, $k) {
        $val = 0;
        $this->helper($root, $k, $val);
        return $val;
    }
    
    private $i = 0;
    
    function helper($root, $k, &$val){
        if($root == null) return ;
        $this->helper($root->left, $k, $val);
        if($k==++$this->i){
            $val = $root->val;
        }
        $this->helper($root->right, $k, $val);
    }
}
```
