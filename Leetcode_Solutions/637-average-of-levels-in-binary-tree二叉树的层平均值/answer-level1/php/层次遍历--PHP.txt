### 解题思路
按层遍历即可

### 性能
执行用时 :16 ms, 在所有 PHP 提交中击败了88.89%的用户
内存消耗 :18.3 MB, 在所有 PHP 提交中击败了28.57%的用户

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
     * @return Float[]
     */
    function averageOfLevels($root) {
        $levels = [];
        $this->levelOrder($root, 0, $levels);

        $res = [];
        foreach ($levels as $level) {
            $res[] = array_sum($level) / count($level);
        }

        return $res;
    }

    public function levelOrder($node, $level, &$res)
    {
        if ($node == null) return;

        $res[$level][] = $node->val;
        $this->levelOrder($node->left, $level + 1, $res);
        $this->levelOrder($node->right, $level + 1, $res);
    }
}
```

### 算法复杂度
- 时间复杂度：
- 空间复杂度：

### 参考
102. 二叉树的层次遍历