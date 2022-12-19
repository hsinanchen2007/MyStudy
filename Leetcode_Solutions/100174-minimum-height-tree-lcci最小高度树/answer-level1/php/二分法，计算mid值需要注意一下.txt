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
        return $this->helper($nums,0, count($nums));
    }

    function helper($nums, $left, $right){
        if( $left == $right){
            return null;
        }

        $mid = floor(($left + $right) / 2);
        $node = new TreeNode($nums[$mid]);
        $node->left = $this->helper($nums, $left, $mid);
        $node->right = $this->helper($nums, $mid + 1, $right);
        return $node;
    }
}
```