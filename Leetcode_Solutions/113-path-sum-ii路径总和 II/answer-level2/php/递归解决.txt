### 解题思路
递归思路与[112](https://leetcode-cn.com/problems/path-sum/)题一致，递归返回结果略有不同，和需要对返回结果进行操作。
递归结束条件 为left right为null，即当前节点为叶子节点。
返回值为[]或[[$root->val]]，递归回父节点后进行merge操作并遍历merge结果，再每个元素数组内开头插入本节点数值。 直至递归回根节点。

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
     * @param Integer $sum
     * @return Integer[][]
     */
    function pathSum($root, $sum) {
        if ($root === null) {
            return [];
        }
        $sum -= $root->val;
        if ($root->left ===null && $root->right === null) {
            if ($sum === 0) {
                return [[$root->val]];
            } else {
                return [];
            }
        }

        $left = $this->pathSum($root->left, $sum);
        $right = $this->pathSum($root->right, $sum);

        $merge = array_merge($left,$right);

        foreach ($merge as &$result) {
            array_unshift($result, $root->val);
        }

        return $merge;
    }
}
```