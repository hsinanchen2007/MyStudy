### 解题思路

换汤不换药。和104题的迭代方法思路一样。利用队列（php就直接用数组了）将每层的子节点先推入队列后去掉当前节点。遍历完节点后，队列中只剩下了下一层所有的节点了。后面就很好解决了。

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
        if (!$root) return [];
        $trees = [$root];
        $levels = [[$root->val]];
        
        while (1) {
            foreach ($trees as $tree) {
                if ($tree->left) {
                    array_push($trees, $tree->left);
                    $level[] = $tree->left->val;
                }
                if ($tree->right) {
                    array_push($trees, $tree->right);
                    $level[] = $tree->right->val;
                }
                array_shift($trees);
            }
            if (!$trees) return $levels;
            array_unshift($levels, $level);
            unset($level);
        }
    }
}
```