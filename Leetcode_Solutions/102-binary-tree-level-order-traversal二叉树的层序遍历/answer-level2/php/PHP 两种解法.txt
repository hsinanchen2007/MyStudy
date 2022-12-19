### 广度优先搜索
使用一个辅助队列实现。

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
        if ($root === null) return $res;
        $queue = new SplQueue();
        $queue->enqueue($root);
        while ($count = $queue->count()) {
            $currentLevel = [];
            for ($i = 0; $i < $count; ++$i) {
                $node = $queue->dequeue();
                $currentLevel[] = $node->val;
                if ($node->left !== null) {
                    $queue->enqueue($node->left);
                }
                if ($node->right !== null) {
                    $queue->enqueue($node->right);
                }
            }
            $res[] = $currentLevel;
        }
        return $res;
    }
}
```

### 深度优先搜索，递归实现

需要记录每一个节点的层级，不连续输出

```php
class Solution {
    protected $result = [];
    /**
     * @param TreeNode $root
     * @return Integer[][]
     */
    function levelOrder1($root) {
        $this->dfs4LevelOrder($root, 0);
        return $this->result;
    }

    private function dfs4LevelOrder($root, $level)
    {
        if ($root === null) return;

        $this->result[$level][] = $root->val;
        $this->dfs4LevelOrder($root->left, $level + 1);
        $this->dfs4LevelOrder($root->right, $level + 1);
    }
}
```
