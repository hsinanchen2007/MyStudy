### 解题思路
1. 前序遍历

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
    function mirrorTree($root) {
        if($root == null) {
            return;
        }

        // 复制时用深复制，以防万一
        $tmp = serialize($root->left);
        $root->left = $root->right;
        $root->right = unserialize($tmp);

        $this->mirrorTree($root->left);
        $this->mirrorTree($root->right);

        return $root;
    }
}
```