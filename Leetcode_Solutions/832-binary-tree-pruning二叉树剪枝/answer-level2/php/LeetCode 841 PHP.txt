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
     * @return TreeNode
     */
    function pruneTree($root) {
        //终止条件
        if($root ==null) return null;
        $right = $this->pruneTree($root->right);
        $left = $this->pruneTree($root->left);
        if(!$left) $root->left = null;
        if(!$right) $root->right = null;
        return ($root->val || $left || $right)? $root:null;
    }
}
```