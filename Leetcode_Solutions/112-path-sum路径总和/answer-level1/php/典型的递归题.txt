### 解题思路
典型的递归题

算法：
0、使用递归法
1、在整颗树上找和为sum的路径。可以转换为在左子树上找$sum - $root的值，在右孩子上找$sum - $root的值。即递推公式$sum = $sum - $root->val。
2、终止条件为到叶节点了，如果$sum为0就说明存在，否则不存在。
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
/*

*/
class Solution {

    /**
     * @param TreeNode $root
     * @param Integer $sum
     * @return Boolean
     */
    function hasPathSum($root, $sum) {
        if ($root === null) {
            return false;
        }

        $sum = $sum - $root->val;

        if ($root->left === null && $root->right === null) {
            // 这种写法很优雅
            return $sum == 0;
        }

        return $this->hasPathSum($root->left, $sum) OR $this->hasPathSum($root->right, $sum);
    }
}
```