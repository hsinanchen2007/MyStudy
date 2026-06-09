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
     * @param Integer[] $nums
     * @return TreeNode
     */
    function sortedArrayToBST($nums) {
        return $this->sortedArrayToBSTHelper(0, count($nums) - 1, $nums);
    }

    /**
     * 递归帮助函数
     *
     * @param int $left
     * @param int $right
     * @param array $nums
     * @return TreeNode
     */
    private function sortedArrayToBSTHelper(int $left, int $right, array $nums)
    {
        if ($left > $right) {
            return null;
        }

        $mid = ($left + $right) / 2;
        $mid = ceil($mid);
        

        $tree = new TreeNode($nums[$mid]);
        $tree->left = $this->sortedArrayToBSTHelper($left, $mid - 1, $nums);
        $tree->right = $this->sortedArrayToBSTHelper($mid + 1, $right, $nums);
        return $tree;
    }
}
```