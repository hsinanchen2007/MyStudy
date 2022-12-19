### 解题思路
见代码

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
     * @return Integer[][]
     */
    function levelOrder($root) {
        $res = [];
        if(empty($root)) return $res;
        $queue = new SplQueue();
        $queue->enqueue([0=>$root]);
        while(!$queue->isEmpty()){
            $data = $queue->dequeue();
            
            foreach ($data as $k=>$node){
                $res[$k][]=$node->val;
                if($node->left != null){
                    $queue->enqueue([$k+1=>$node->left]);
                }
                if($node->right != null){
                    $queue->enqueue([$k+1=>$node->right]);
                }
            }
        }
        return $res;
    }
}
```