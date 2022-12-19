### 解题思路
递归实现

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
     * @param Integer $val
     * @return TreeNode
     */
    function searchBST($root, $val) {
        if ($root == null || $root->val == $val) return $root;

        return $root->val > $val ? $this->searchBST($root->left, $val) : $this->searchBST($root->right, $val);
    }
}
```

### 算法复杂度
- 时间复杂度: O(n)
- 空间复杂度: O(log n)