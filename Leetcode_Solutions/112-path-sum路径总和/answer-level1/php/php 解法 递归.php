```
class Solution {
    function hasPathSum($root, $sum) {
        if($root == null) return false;
        return $this->helper($root,0,$sum);
    }
    
    function helper($node,$sum,$target){
        $sum += $node->val;
        if($node->left == null && $node->right == null && $sum == $target) return true;
        if($node->left == null && $node->right == null && $sum != $target) return false;
        
        if($node->left != null) $m1 = $this->helper($node->left,$sum,$target);
        if($m1) return true;
        if($node->right != null) $m2 = $this->helper($node->right,$sum,$target);
        if($m2) return true;
        return false;
    }
    
}
```
优化代码：
```
class Solution {
    function hasPathSum($root, $sum) {
        if($root == null) return false;
        $sum -= $root->val;
        if($root->left == null && $root->right == null) return $sum==0;
        return $this->hasPathSum($root->left, $sum) || $this->hasPathSum($root->right, $sum);
    }
}
```
