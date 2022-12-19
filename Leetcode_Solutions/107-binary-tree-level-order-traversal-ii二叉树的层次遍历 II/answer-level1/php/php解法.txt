### 解题思路
此处撰写解题思路

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
    function levelOrderBottom($root) {
        if ($root == null) {
            return [];
        }
        $back = [];
        $this->levelOrderBottomHelper($root, 0, $back);
        return $back;
    }
    /**
     * @param TreeNode $root
     * @param int $level
     * @param array $res
     * @return mixed
     */
    private function levelOrderBottomHelper(TreeNode $root, int $level, array &$res)
    {
        if (count($res) == $level) {
            array_unshift($res, []);
        }

        array_push($res[count($res) - $level - 1], $root->val);
        if ($root->left) {
            $this->levelOrderBottomHelper($root->left, $level+1, $res);
        }
        if ($root->right) {
            $this->levelOrderBottomHelper($root->right, $level+1, $res);
        }
        
    }
}
```