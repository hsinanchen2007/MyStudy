二叉树前序遍历
```
class Solution {

    /**
     * @param TreeNode $root
     * @return String[]
     */
    function binaryTreePaths($root) {
        $ans = [];
        $this->helper($root, "", $ans);
        return $ans;
    }
    
    function helper($root, $path, &$ans){
        if($root == null) return ;
        $path .= (string)$root->val;
        if($root->left==null && $root->right==null) $ans[] = $path;
        $this->helper($root->left, $path."->", $ans);
        $this->helper($root->right, $path."->", $ans);
    }
}
```
