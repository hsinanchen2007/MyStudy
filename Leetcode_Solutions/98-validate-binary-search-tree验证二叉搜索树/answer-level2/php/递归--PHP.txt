### 解题思路
递归处理

### 性能
执行用时 :12 ms, 在所有 PHP 提交中击败了85.71%的用户
内存消耗 :17.7 MB, 在所有 PHP 提交中击败了16.67%的用户

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
     * @return Boolean
     */
    function isValidBST($root) {
        return $this->task($root, null, null);
    }
    
    public function task($node, $lower, $upper)
    {
        if ($node == null) return true;
        $val = $node->val;

        // $lower可能为0(o == null)这你需要用 !==
        if ($lower !== null && $val <= $lower) return false;
        if ($upper !== null && $val >= $upper) return false;

        // 左子树就检查上界, 都小于当前节点，右子树检查下界，都大于当前节点
        if (!$this->task($node->left, $lower, $val)) return false;
        if (!$this->task($node->right, $val, $upper)) return false;

        return true;
    }
}
```

### 算法复杂度
- 时间复杂度 O（N）
- 空间复杂度 O（N）

### 参考
[https://leetcode-cn.com/problems/validate-binary-search-tree/solution/yan-zheng-er-cha-sou-suo-shu-by-leetcode/](https://leetcode-cn.com/problems/validate-binary-search-tree/solution/yan-zheng-er-cha-sou-suo-shu-by-leetcode/)