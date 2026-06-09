### 解题思路

二叉树的层序遍历

### 代码

```php
/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     public $val = null;
 *     public $left = null;
 *     public $right = null;
 *     function __construct($value) { $this->val = $value; }
 * }
 */
class Solution {
    /**
     * @param TreeNode $root
     * @return Integer
     */

    function maxLevelSum($root) {
        $node_arr = [$root];
        $max_sum = 0;
        $max_level = 1;
        $i = 1;
        while($node_arr) {
            $child_node_arr = [];
            $sum = 0;
            foreach($node_arr as $node) {
                if(null !== $node->left) {
                    $child_node_arr[] = $node->left;
                }
                if(null !== $node->right) {
                    $child_node_arr[] = $node->right;
                }
                $sum += $node->val;
            }
            if($sum > $max_sum) {
                $max_sum = $sum;
                $max_level = $i;
            }
            $i++;
            $node_arr = $child_node_arr;
        }
        return $max_level;
    }
}
```