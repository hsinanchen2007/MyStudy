# 二叉树的最大深度

    见解：这里只需要求出二叉树的深度，
         所以不管是使用前序、中序、后序遍历方式都是很麻烦的
         因为需要每个树都单独遍历一次！

    解法：使用二叉树的层次遍历
        只要这一层还有树节点，我就往下深入一层

```
function maxDepth($root) {
    if(!$root) return 0;
    $depth = 1;
    $pnodes = [$root];
    while($pnodes){
        $nodes = [];
        foreach($pnodes as $pnode){
            if($pnode->left){
                $nodes[] = $pnode->left;
            }
            if($pnode->right){
                $nodes[] = $pnode->right;
            }
        }
        if(!count($nodes)) return $depth;
        $pnodes = $nodes;
        $depth++;
    }
}
```
