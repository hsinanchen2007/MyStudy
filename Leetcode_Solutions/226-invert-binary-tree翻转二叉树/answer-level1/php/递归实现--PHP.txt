### 解题思路
算法：
0、根为null, 直接返回
1、分别反转左子树和右子树
2、把反转的左子树赋值给右子树，同理把反转的右子树赋值给左子树。
3、返回根节点。

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
    function invertTree($root) {
        if ($root == null) {
            return $root;
        }

        $left = $this->invertTree($root->left);
        $right = $this->invertTree($root->right);

        $root->left = $right;
        $root->right = $left;

        return $root;
    }
}
```