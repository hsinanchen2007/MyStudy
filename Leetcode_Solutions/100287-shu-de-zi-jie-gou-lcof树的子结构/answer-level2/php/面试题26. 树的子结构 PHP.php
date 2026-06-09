### 解题思路
1. 遍历，遍历，遍历！
2. 二叉树的遍历不能放在 dfs 函数，否则 is_null 部分会误判

### 代码

```php
class Solution {

    /**
     * @param TreeNode $A
     * @param TreeNode $B
     * @return Boolean
     */
    function isSubStructure($A, $B) {
        if(is_null($A) || is_null($B)) {
            return false;
        }

        return $this->dfs($A, $B) || $this->isSubStructure($A->left, $B) || $this->isSubStructure($A->right, $B);


    }

    function dfs($A, $B) {

        // B 结束了 -> OK
        if($B == null) {
            return true;
        }

        // B 没结束但是 A 结束了 -> 不行
        if($A == null AND $B != null) {
            return false;
        }

        // AB 相等则继续判断左右子树
        return $A->val == $B->val && $this->dfs($A->left, $B->left) && $this->dfs($A->right, $B->right);
    }
}
```