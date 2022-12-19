### 解题思路
其实就是简单的递归

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
    function sumOfLeftLeaves($root) {
        $sum = 0;

        if(!is_null($root->left)){
            if(is_null($root->left->left) && is_null($root->left->right)){
                $sum += $root->left->val;
            }
            $sum += $this->sumOfLeftLeaves($root->left);
        }

        if(!is_null($root->right)){
            $sum += $this->sumOfLeftLeaves($root->right);
        }

        return $sum;
    }
}
```