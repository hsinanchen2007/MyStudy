### 解题思路
具体见代码

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
     * @return Integer[]
     */
    function levelOrder($root) {
        $res = [];
        $queue = new SplQueue();
        $queue->enqueue($root);
        while(!$queue->isEmpty()){
            $node = $queue->dequeue();
            array_push($res,$node->val);
            if($node->left!=null){
                $queue->enqueue($node->left);
            }

            if( $node->right!=null){
                $queue->enqueue($node->right);
            }
        }
        return $res;

    }
}
```