使用一个辅助队列，每次遍历一层。
一次取出一层，进行处理

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
    function largestValues($root) {
        $res = [];
        if ($root === null) return $res;
        $queue = new SplQueue();
        $queue->enqueue($root);
        while ($count = $queue->count()) {
            $currentLevelMax = PHP_INT_MIN;
            for ($i = 0; $i < $count; ++$i) {
                $node = $queue->dequeue();
                $currentLevelMax = max($currentLevelMax, $node->val);
                if ($node->left !== null) {
                    $queue->enqueue($node->left);
                }
                if ($node->right !== null) {
                    $queue->enqueue($node->right);
                }
            }
            $res[] = $currentLevelMax;
        }

        return $res;
    }
}
```