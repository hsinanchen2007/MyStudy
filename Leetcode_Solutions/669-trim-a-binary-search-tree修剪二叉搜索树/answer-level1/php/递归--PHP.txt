### 解题思路
递归，如果当前节点比L小，只取其右子树，如果比R大只取其左子树。

### 性能
执行用时 :20 ms, 在所有 PHP 提交中击败了66.67%的用户
内存消耗 :18.2 MB, 在所有 PHP 提交中击败了100.00%的用户

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
     * @param Integer $L
     * @param Integer $R
     * @return TreeNode
     */
    function trimBST($root, $L, $R) {
        if ($root == null) return $root;

        if ($root->val > $R) return $this->trimBST($root->left, $L, $R);
        if ($root->val < $L) return $this->trimBST($root->right, $L, $R);

        $root->left = $this->trimBST($root->left, $L, $R);
        $root->right = $this->trimBST($root->right, $L, $R);

        return $root;
    }
}
```

### 算法复杂度
- 时间复杂度: O(N)
- 空间复杂度: O(1)

### 参考
[https://leetcode-cn.com/problems/trim-a-binary-search-tree/solution/xiu-jian-er-cha-sou-suo-shu-by-leetcode/](https://leetcode-cn.com/problems/trim-a-binary-search-tree/solution/xiu-jian-er-cha-sou-suo-shu-by-leetcode/)