### 解题思路
中序遍历，计算当前节点和前驱节点的差值，比最小值小，更新最小值。

问题：
[1,null,3,2]题目说明中的这个二叉树是二叉搜索树吗？另外任何两个节点，不要求相邻吗？

### 性能
执行用时 :12 ms, 在所有 PHP 提交中击败了100.00%的用户
内存消耗 :17.2 MB, 在所有 PHP 提交中击败了14.29%的用户

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
    function getMinimumDifference($root) {
        $pre = null;
        $min = PHP_INT_MAX;
        $this->inOrderTask($root, $pre, $min);
        return $min;
    }

    public function inOrderTask($node, &$pre, &$min)
    {
        if ($node == null) return;
        $this->inOrderTask($node->left, $pre, $min);
        if ($pre) {
            $min = min(abs($node->val - $pre->val), $min);
        }
        $pre = $node;
        $this->inOrderTask($node->right, $pre, $min);
    }


}
```