### 解题思路
递归思路

1、找到最大值
2、通过最大值获取左数组和右数组
3、分治->递归获取左子树和右子树

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
     * @param Integer[] $nums
     * @return TreeNode
     */
    function constructMaximumBinaryTree($nums) {
        if(empty($nums)) return null;
        $max = max($nums);
        $index = array_search($max,$nums);
        $left = array_slice($nums,0,$index);
        $right = array_slice($nums,$index+1);
        $root = new TreeNode($max);
        $root->left = $this->constructMaximumBinaryTree($left);
        $root->right = $this->constructMaximumBinaryTree($right);
        return $root;
    }
}
```