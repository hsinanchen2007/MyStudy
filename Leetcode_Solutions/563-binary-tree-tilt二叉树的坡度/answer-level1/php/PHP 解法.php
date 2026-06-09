重点是一定要明确递归函数的定义。
还有，最终返回值可能与递归函数的返回值不一致，在中途进行处理。

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
    protected $result = 0;
    /**
     * @param TreeNode $root
     * @return Integer
     */
    function findTilt($root) {
        $this->helper($root);
        return $this->result;
    }

    // 明确递归函数的含义：返回以当前节点为根节点的二叉树所有节点之和 (包含根节点)
    private function helper($node)
    {
        if ($node === null) return 0;
        $left = $this->helper($node->left);
        $right = $this->helper($node->right);
        $this->result += abs($left - $right);
        return $left + $right + $node->val;
    }
}
```