
递归
```
class Solution {

    /**
     * @param TreeNode $root
     * @return Integer[]
     */
    function preorderTraversal($root) {
        if(empty($root)) {
            return [];
        }
        $arr = [$root->val];
        $a = $this->preorderTraversal($root->left);
        $b = $this->preorderTraversal($root->right);
    
 
        return array_merge($arr, $a , $b);
    }
}
```

迭代

```
class Solution {

    /**
     * @param TreeNode $root
     * @return Integer[]
     */
    function preorderTraversal($root) {
        if(empty($root)) {
            return [];
        }
        
        $stack = [$root];
        $output = [];
        
        while (count($stack)){
        	$node = array_pop($stack);
        	$output[] = $node->val;
        	if ($node->right) {
        		$stack[] = $node->right;
        	}
        	
        	if ($node->left) {
        		$stack[] = $node->left;
        	}
        }

        return $output;
    }
}
```