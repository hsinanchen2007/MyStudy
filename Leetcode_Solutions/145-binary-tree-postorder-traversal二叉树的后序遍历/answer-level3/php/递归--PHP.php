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
    function postorderTraversal($root) {
        $res = [];
        $this->task($root, $res);
        
        return $res;
    }
    
    public function task($node, &$res)
    {
        if ($node == null) return $res;
        
        $this->task($node->left, $res);
        $this->task($node->right, $res);
        $res[] = $node->val;
    }
}
```

### 性能
执行用时 :8 ms, 在所有 PHP 提交中击败了53.01%的用户
内存消耗 :14.9 MB, 在所有 PHP 提交中击败了61.54%的用户