### 解题思路
求左右子树的深度 + 1

### 性能
执行用时 :16 ms, 在所有 PHP 提交中击败了42.11%的用户
内存消耗 :17 MB, 在所有 PHP 提交中击败了100.00%的用户

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
    function diameterOfBinaryTree($root) {
        $max = 0;
        if ($root == null) return $max;

        $this->deep($root, $max);

        return $max;
    }

    public function deep($node, &$max)
    {
        if ($node == null) return 0;

        $left = $this->deep($node->left, $max);
        $right = $this->deep($node->right, $max); 
        
        $max = max($max, $left + $right);
        return max($left, $right) + 1;
    }
}
```