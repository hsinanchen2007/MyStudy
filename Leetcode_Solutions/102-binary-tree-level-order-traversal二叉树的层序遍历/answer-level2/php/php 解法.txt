```
class Solution {

    /**
     * @param TreeNode $root
     * @return Integer[][]
     */
    function levelOrder($root) {
        if($root === null) return [];
        $res = [];
        $this->helper($root,0,$res);
        return $res;
    }
    
    function helper($node,$level,&$res){
        if(count($res) == $level) $res[$level] = [];
        array_push($res[$level],$node->val);
        if($node->left!==null) $this->helper($node->left,$level+1,$res);
        if($node->right!==null) $this->helper($node->right,$level+1,$res);
    }
}
```
