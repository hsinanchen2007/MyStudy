### 解题思路
反中序遍历

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
    function convertBST($root)
    {
        $num = 0;
        $this->inOrder($root, $num);

        return $root;
    }
    //&$num 这个一定要加&,用来累加数据
    /**
     * @param TreeNode $node
     * @param $num
     */
    function inOrder(&$node, &$num)
    {
        if ($node == null) {
            return;
        }
        $this->inOrder($node->right, $num);
        $node->val += $num;
        $num = $node->val;
        $this->inOrder($node->left, $num);
    }
}
