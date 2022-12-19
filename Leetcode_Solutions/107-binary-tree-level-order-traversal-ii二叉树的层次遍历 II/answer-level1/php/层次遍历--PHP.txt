### 解题思路
一种思路是层次遍历，然后取反。这里是在层次遍历的过程中，反着填充数据。

### 性能
执行用时 :12 ms, 在所有 PHP 提交中击败了52.17%的用户
内存消耗 :15.9 MB, 在所有 PHP 提交中击败了27.91%的用户

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
     * @return Integer[][]
     */
    function levelOrderBottom($root) {
        $res = [];
        if ($root == null) {
            return $res;
        }

        $level = 0;
        $this->helper($root, $level, $res);

        return $res;
    }

    public function helper($node, $level, &$res)
    {
        if ($node == null) return;

        // array_unshift新增的元素key永远是0
        if (count($res) == $level) array_unshift($res, []);

        // count($res) - $level - 1的值始终为0，所以总是在开头插入, 这个理解是有问题的。count($res) - $level - 1可能不为0，比如case[1,2,3,4,5]最后为1。这里只是反着收集数据。
        array_push($res[count($res) - $level - 1], $node->val);
        $this->helper($node->left, $level + 1, $res);
        $this->helper($node->right, $level + 1, $res);
    }
}
```

### 算法复杂度
- 时间复杂度 O(N)
- 空间复杂度 O(1)

### 参考