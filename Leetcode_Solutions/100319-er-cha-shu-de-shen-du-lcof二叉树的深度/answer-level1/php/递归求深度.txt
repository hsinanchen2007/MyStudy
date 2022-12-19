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
        if(empty($root)){
            return 0;
        }
        //左边深度和右边深度取最大
        $root->left && $left=$this->maxDepth($root->left);
        $root->right && $right=$this->maxDepth($root->right);
        return max($left,$right)+1;
    }
}
```