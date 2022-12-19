```
// 替换函数
function swap(&$i,&$j){
    $tmp = $i;
    $i = $j;
    $j = $tmp;
}
// 前序遍历
function invertTree($root) {
    if($root == null) return ;
    $this->swap($root->left,$root->right);
    $this->invertTree($root->left);
    $this->invertTree($root->right);
    return $root;
}
// 后续遍历
function invertTree($root) {
    if($root == null) return ;
    $this->invertTree($root->left);
    $this->invertTree($root->right);
    $this->swap($root->left,$root->right);
    return $root;
}
// 中序遍历
function invertTree($root) {
    if($root == null) return ;
    $this->invertTree($root->left);
    $this->swap($root->left,$root->right);
    $this->invertTree($root->left); // $root->left和$root->right已经替换
    return $root;
}
```
