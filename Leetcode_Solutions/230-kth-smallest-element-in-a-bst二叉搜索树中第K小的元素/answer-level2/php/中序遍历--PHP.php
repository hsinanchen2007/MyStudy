### 解题思路
中序遍历后，是递增的，取第$k个元素即可。

**为啥PHP代码模板中方法没有访问属性(public), 其他语言都有啊，什么鬼。**

### 性能
执行用时 :12 ms, 在所有 PHP 提交中击败了100.00%的用户
内存消耗 :18.4 MB, 在所有 PHP 提交中击败了11.76%的用户

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
     * @param Integer $k
     * @return Integer
     */
    function kthSmallest($root, $k) {
        $res = [];
        $this->inorder($root, $res);

        return $res[$k - 1];
    }

    public function inorder($node, &$res)
    {
        if ($node == null) return null;

        $this->inorder($node->left, $res);
        $res[] = $node->val;
        $this->inorder($node->right, $res);
    }
}
```

### 算法复杂度
- 时间复杂度 O(N)
- 空间复杂度 O(N)

### 参考
无