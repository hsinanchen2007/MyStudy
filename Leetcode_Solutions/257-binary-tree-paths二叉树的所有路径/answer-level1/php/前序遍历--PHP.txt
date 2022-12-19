### 解题思路
前序遍历

### 性能
执行用时 :4 ms, 在所有 php 提交中击败了100.00%的用户
内存消耗 :15 MB, 在所有 php 提交中击败了14.29%的用户

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
     * @return String[]
     */
    function binaryTreePaths($root) {
        $res = [];
        $this->run($root, '', $res);

        return $res;
    }

    public function run($node, $val, &$res)
    {
        if ($node == null) {
            return $res;
        }

        $val .= $node->val;
        if ($node->left == null && $node->right == null) {
            $res[] = $val;
        }

        $val .= '->';
        $this->run($node->left, $val, $res);
        $this->run($node->right, $val, $res);
    }
}
```