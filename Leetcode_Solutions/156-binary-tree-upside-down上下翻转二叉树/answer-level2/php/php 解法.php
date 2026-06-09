```
function upsideDownBinaryTree($root) {
    $old_right = $old = null;
    while($root != null){
        $tmp = $root->left; // root->left是下一轮递归的主节点；
        $root->left = $old_right; //old_right是下一轮递归root的root->left。
        $old_right = $root->right;
        $root->right = $old; //old是下一轮递归root的root->right；
        $old = $root;
        $root = $tmp;
    }
    return $old;
}
```
