递归解法：
每次递归给root->left->next和root->right->next赋值
```
function connect($root) {
    if($root == null) return null;
    if($root->left != null){
        $root->left->next = $root->right;
        if($root->next != null) $root->right->next = $root->next->left;
    }
    $this->connect($root->left);
    $this->connect($root->right);
    return $root;
}
```
