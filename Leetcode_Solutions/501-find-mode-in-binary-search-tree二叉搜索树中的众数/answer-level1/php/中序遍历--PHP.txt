### 解题思路
对当前节点计数。画图有助于理解。

### 性能
执行用时 :16 ms, 在所有 PHP 提交中击败了100.00%的用户
内存消耗 :18.5 MB, 在所有 PHP 提交中击败了100.00%的用户

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
    function findMode($root) {
        $pre = null;
        $cur_times = 1;
        $max_times = 0;

        $res = [];
        $this->inorderTraversal($root, $pre, $cur_times, $max_times, $res);
        return $res;
    }

    public function inorderTraversal($node, &$pre, &$cur_times, &$max_times, &$res)
    {
        if ($node == null) return;
        
        $this->inorderTraversal($node->left, $pre, $cur_times, $max_times, $res);
        if ($pre != null) {
            $cur_times = ($node->val == $pre->val) ? $cur_times + 1 : 1;
        }

        if ($cur_times == $max_times) {
            $res[] = $node->val;
        } elseif ($cur_times > $max_times) {
            $res = [];
            $res[] = $node->val;
            $max_times = $cur_times;
        }

        // 注意pre的移动
        $pre = $node;
        $this->inorderTraversal($node->right, $pre, $cur_times, $max_times, $res);
    }
}
```

参考：
[二叉搜索树中的众数](https://leetcode-cn.com/problems/find-mode-in-binary-search-tree/solution/er-cha-sou-suo-shu-zhong-de-zhong-shu-by-junstat/)