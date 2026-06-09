### 解题思路
递归实现，层次遍历

发现很多人的递归终止条件是单独检查是否有左右节点，反倒不如在开始就检查节点理解容易。
```
if ($node->left != null) {
    $this->task($node->left, $level + 1, $res);
}
```


### 性能
执行用时 :12 ms, 在所有 PHP 提交中击败了40.21%的用户
内存消耗 :16 MB, 在所有 PHP 提交中击败了8.57%的用户

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
        if ($root == null) return $res;

        $this->task($root, 0, $res);
        
        return $res;
    }
    
    public function task($node, $level, &$res)
    {
        if ($node == null) return;

        if (count($res) == $level) $res[$level] = [];

        $res[$level][] = $node->val;
        
        $this->task($node->left, $level + 1, $res);
        $this->task($node->right, $level + 1, $res);
    }
}
```

### 算法复杂度
- 时间复杂度 O(N)
- 空间复杂度 O(N)

### 参考