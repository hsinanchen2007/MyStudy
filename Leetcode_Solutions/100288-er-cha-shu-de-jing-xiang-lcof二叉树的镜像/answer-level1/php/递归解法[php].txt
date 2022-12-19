### 解题思路
观察题目，我们知道这是左右子树交换。

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
        if($root==null){
            return ;
        }

        $tmp = $root -> right;
        $root->right = $root->left;
        $root->left = $tmp;

        $this->mirrorTree($root->left);
        $this->mirrorTree($root->right);
        return $root;
    }
}
```