### 解题思路
递归，遍历根，左，右；然后再合并数组
执行用时 :8 ms, 在所有 PHP 提交中击败了58.13%的用户
内存消耗 :14.8 MB, 在所有 PHP 提交中击败了100.00%的用户

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
     * @return Integer[]
     */
    function preorderTraversal($root) {
        if(is_null($root)){
            return [];
        }
        $node = array($root->val);
        $leftnode = $rightnode = array();
        if(!is_null($root->left)){
            $leftnode = $this->preorderTraversal($root->left);
        }
        if(!is_null($root->right)){
            $rightnode = $this->preorderTraversal($root->right);
        }
        return array_merge($node,$leftnode,$rightnode);
    }
}
```