同时对左右两棵树BFS递归，并进行比较
需要注意的是，一般BFS会忽略null值，而此处必须将null值保留，只是递归至null时直接continue


```php
class Solution {

    /**
     * @param TreeNode $root
     * @return Boolean
     */
    function isSymmetric($root) {
        $left = [$root->left];
        $right = [$root->right];
        while (!empty($left) || !empty($right)) {
            $left_tree = array_shift($left);
            $right_tree = array_shift($right);
            if ($left_tree == null && $right_tree == null) {
                continue;
            } else if ($left_tree == null || $right_tree == null) {
                return false;
            }
            if ($left_tree->val != $right_tree->val) {
                return false;
            }
            $left[] = $left_tree->left;
            $left[] = $left_tree->right;
            $right[] = $right_tree->right;
            $right[] = $right_tree->left;
        }
        return true;
    }
}
```