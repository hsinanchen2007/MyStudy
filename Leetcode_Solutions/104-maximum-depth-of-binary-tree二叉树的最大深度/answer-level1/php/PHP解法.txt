初始解法
```
class Solution {

    /**
     * @param TreeNode $root
     * @return Integer
     */
    function maxDepth($root) {
        if($root===null) return 0;
        $maxlevel = 0;
        $this->helper($root,0,$maxlevel);
        return $maxlevel+1;
    }
    
    function helper($root,$level,&$maxlevel){
        $maxlevel = max($level,$maxlevel);
        if($root->left!==null) $this->helper($root->left,$level+1,$maxlevel);
        if($root->right!==null) $this->helper($root->right,$level+1,$maxlevel);
    }
}
```
简化只需一行代码：
```
class Solution {

    /**
     * @param TreeNode $root
     * @return Integer
     */
    function maxDepth($root) {
        return $root===null?0:max($this->maxDepth($root->left),$this->maxDepth($root->right))+1;
    }
}
```