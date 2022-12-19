### 解题思路
中序遍历

说明：inOrderTask(&$node, &$num)，$node是不是引用都可以，$num必须是引用

### 性能
执行用时 :24 ms, 在所有 PHP 提交中击败了100.00%的用户
内存消耗 :19.5 MB, 在所有 PHP 提交中击败了100.00%的用户

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
     * @return TreeNode
     */
    function convertBST($root) {
        $num = 0;
        $this->inOrderTask($root, $num);

        return $root;
    }

    public function inOrderTask(&$node, &$num) {
        if ($node == null) return;

        $this->inOrderTask($node->right, $num);
        $node->val += $num;
        $num = $node->val;
        $this->inOrderTask($node->left, $num);
    }
}
```