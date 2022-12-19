# 对称二叉树
    可以理解为，二叉树每一层都是回文字符串，
    所以使用二叉树的层次遍历法，将每层的树枝遍历出来
    如果不存在用 null 进行占位，
    每获取到一层就进行回文字符串判断

```
function isSymmetric($root) {
        $pnodes = [$root];
        while($pnodes){
            $arr = [];
            $nodes = [];
            foreach($pnodes as $pnode){
                if($pnode->left){
                    $arr[] = $pnode->left->val;
                    $nodes[] = $pnode->left;
                }else{
                    $arr[] = null;
                }
                if($pnode->right){
                    $arr[] = $pnode->right->val;
                    $nodes[] = $pnode->right;
                }else{
                    $arr[] = null;
                }
            }
            
            if(!count($nodes)) return true;
            $pnodes = $nodes;
            $sum = count($arr);
            for($i = 0; $i < $sum; $i++){
                if($arr[$i] !== $arr[$sum - $i - 1]){
                    return false;
                }
                if($i >= $sum - $i - 1) breack;
            }
        }
```
