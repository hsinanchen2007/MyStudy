### 解题思路
中序遍历，然后构建树，注意增加虚拟节点，初始化虚拟节点赋值0.

### 性能
执行用时 :28 ms, 在所有 PHP 提交中击败了80.00%的用户
内存消耗 :15.1 MB, 在所有 PHP 提交中击败了50.00%的用户

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
    function increasingBST($root) {
        $vals = [];
        $this->inOrder($root, $vals);
        $ans = new TreeNode(0);
        $cur = $ans;
        foreach ($vals as $val) {
            $tree = new TreeNode($val);
            $cur->right = new TreeNode($val);
            $cur = $cur->right;
        }

        return $ans->right;
    }

    public function inOrder($node, &$res)
    {
        if ($node == null) return;

        $this->inOrder($node->left, $res);
        $res[] = $node->val;
        $this->inOrder($node->right, $res);
    }
}
```

### 算法复杂度
- 时间复杂度：O(N)
- 空间复杂度: O(N)

### 参考
[https://leetcode-cn.com/problems/increasing-order-search-tree/solution/di-zeng-shun-xu-cha-zhao-shu-by-leetcode/](https://leetcode-cn.com/problems/increasing-order-search-tree/solution/di-zeng-shun-xu-cha-zhao-shu-by-leetcode/)