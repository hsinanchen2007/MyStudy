### 解题思路

只要理解了递归函数的定义，问题就很简单了

### 代码

```php
class Solution {

    /**
     * @param TreeNode $root
     * @return TreeNode
     */
    function invertTree($root) {
        if ($root === null) {
            return $root;
        }

        $left = $root->left;
        $right = $root->right;
        $root->left = $this->invertTree($right);
        $root->right = $this->invertTree($left);
        return $root;
    }
}
```