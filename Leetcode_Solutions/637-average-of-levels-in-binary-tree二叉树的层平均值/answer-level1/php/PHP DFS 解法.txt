在 [102](https://leetcode-cn.com/problems/binary-tree-level-order-traversal/solution/php-liang-chong-jie-fa-by-zzpwestlife-4/) 的基础上改一下即可。

确认 BFS 算法的官方后台有问题，相同的BFS代码在 102 是通过的，在这里就报错。

```php
class Solution
{
    protected $result = [];
    
    function averageOfLevels($root)
    {
        if ($root === null) return $this->result;
        $this->dfs($root, 0);

        $return = [];
        foreach ($this->result as $level) {
            $return[] = array_sum($level) / count($level);
        }
        return $return;
    }

    private function dfs($node, $level)
    {
        if ($node === null) return;
        $this->result[$level][] = $node->val;
        $this->dfs($node->left, $level + 1);
        $this->dfs($node->right, $level + 1);
    }
}
```