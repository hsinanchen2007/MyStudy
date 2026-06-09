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
     * @return Integer
     */
    function maxDepth($root) {
        if($root == null) return 0;
        //在左节点和右节点取max
        if($root->left ==null) return $this->maxDepth($root->right)+1;
        if($root->right ==null) return $this->maxDepth($root->left)+1;
        return max($this->maxDepth($root->left),$this->maxDepth($root->right))+1;
    }
}
```