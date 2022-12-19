```
class Solution {

    /**
     * @param TreeNode $root
     * @return NULL
     */
    
    private $pre = null;
    
    function flatten($root) {
        if($root == null) return ;
        $this->flatten($root->right);
        $this->flatten($root->left);
        $root->right = $this->pre;
        $root->left = null;
        $this->pre = $root;
    }
}
```
