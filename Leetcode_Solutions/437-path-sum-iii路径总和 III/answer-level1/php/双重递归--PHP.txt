### 解题思路
第一次写双重递归，期间出了不少问题。

### 性能
执行用时 :364 ms, 在所有 PHP 提交中击败了7.14%的用户
内存消耗 :15.7 MB, 在所有 PHP 提交中击败了50.00%的用户

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

    private $count = 0;

    /**
     * @param TreeNode $root
     * @param Integer $sum
     * @return Integer
     */
    function pathSum($root, $sum) {
        if ($root == null) return 0;

        $this->Sum($root, $sum);
        
        $this->pathSum($root->left, $sum);
        $this->pathSum($root->right, $sum);

        return $this->count;
    }

    /**
     * @param TreeNode $node
     * @param Integer $sum
     * @return null
     */
    public function Sum($node, $sum)
    {
        if ($node == null) return;

        $sum -= $node->val;
        if ($sum == 0) $this->count++;

        $this->Sum($node->left, $sum);
        $this->Sum($node->right, $sum);
    }
}
```

参考：
[Java双重递归](https://leetcode-cn.com/problems/path-sum-iii/comments/9611)