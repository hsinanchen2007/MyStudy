思路
递归的方式：
两者都比root大，则从右边找；
两者都比root小，则从左边找；
否则返回根节点
```
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
     * @param  $p
     * @param  $q
     * @return Integer
     */
    function lowestCommon($root, $p, $q) {

        if ($root->val > $p && $root->val > $q) {
            return $this->lowestCommon( $root->left, $p, $q );
        }

        if ($root->val < $p && $root->val < $q) {
            return $this->lowestCommon( $root->rights, $p, $q );
        }

        return $root;
    }

}
```
