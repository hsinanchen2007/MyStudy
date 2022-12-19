
```
    function postorderTraversal($root) {
        $res = [];
        $stack = [];
        $outStack = [];
        array_push($stack,$root);
        while ($stack) {
            $node = array_pop($stack);
            $outStack[] = $node;
            if ($node->left) {
                array_push($stack,$node->left);
            }
            if ($node->right) {
                array_push($stack,$node->right);
            }
        }
        while ($outStack) {
            $node = array_pop($outStack);
            $res[] = $node->val;
        }
        return $res;
    }
```
