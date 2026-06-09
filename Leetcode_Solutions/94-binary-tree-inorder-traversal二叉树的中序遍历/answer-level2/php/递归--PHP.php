### 解题思路
递归。

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
    function inorderTraversal($root) {
        $res = [];
        $this->task($root, $res);
        
        return $res;
    }
    
    public function task($node, &$res)
    {
        if ($node == null) return $res;
        
        $this->task($node->left, $res);
        $res[] = $node->val;
        $this->task($node->right, $res);
    }
}
```

### 性能
执行用时 :12 ms, 在所有 PHP 提交中击败了12.90%的用户
内存消耗 :15.1 MB, 在所有 PHP 提交中击败了11.11%的用户

### 算法复杂度
-- 时间复杂度 O(N)
-- 空间复杂度 O(N)

### 参考