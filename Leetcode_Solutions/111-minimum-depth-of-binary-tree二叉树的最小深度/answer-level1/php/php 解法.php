```
function minDepth($root) {
    if($root == null) return 0;
    if($root->left == null && $root->right == null) return 1;
    if($root->left != null)
        $minDepth = isset($minDepth)?min($this->minDepth($root->left),$minDepth):$this->minDepth($root->left);
    if($root->right != null)
        $minDepth = isset($minDepth)?min($this->minDepth($root->right),$minDepth):$this->minDepth($root->right);
    return $minDepth+1;
}
```
