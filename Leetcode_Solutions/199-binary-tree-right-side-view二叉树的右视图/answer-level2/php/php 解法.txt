```
class Solution {

    /**
     * @param TreeNode $root
     * @return Integer[]
     */
    function rightSideView($root) {
        $list = [];
        $this->helper($root, 0, $list);
        return $list;
    }
    
    function helper($root, $depth, &$list){
        if($root == null) return ;
        if($depth == count($list)) $list[] = $root->val;
        $this->helper($root->right,$depth+1,$list);
        $this->helper($root->left,$depth+1,$list);
    }
}
```
